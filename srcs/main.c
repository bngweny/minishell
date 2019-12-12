/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngweny <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 14:59:35 by bngweny           #+#    #+#             */
/*   Updated: 2018/09/15 13:56:52 by bngweny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec(char **args, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		ft_printf("\nFailed forking child..");
		return ;
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, env) < 0)
			ft_printf("Could not execute command..\n");
		return ;
	}
	else
	{
		wait(NULL);
		return ;
	}
}

void	executebin(char **args, char **env)
{
	char	*path;
	int		i;

	i = 0;
	path = get_binpath(args[i]);
	if (!path)
		ft_printf("minishell: command not found: %s\n", args[i]);
	else
	{
		free(args[i]);
		args[i] = path;
		exec(args, env);
	}
}

int		execute_cmd(char **args, char **env)
{
	int		i;

	i = 0;
	if (args[i])
	{
		if (!ft_strcmp(args[i], "env"))
			print_evv(env);
		else if (!ft_strcmp(args[i], "clear"))
			CLEAR();
		else if (!ft_strcmp(args[i], "exit"))
			return (0);
		else if (!ft_strcmp(args[i], "echo"))
			echo_built(args);
		else if (!ft_strcmp(args[i], "setenv"))
			set_env(args);
		else if (!ft_strcmp(args[i], "unsetenv"))
			unset_env(args);
		else if (!ft_strcmp(args[i], "cd"))
			change_dir(args[i + 1]);
		else
			executebin(args, env);
	}
	return (1);
}

void	execpipe(char **parsed, char** parsedpipe)
{
	int		pipefd[2];
	pid_t	p1;
	pid_t	p2;

	if (pipe(pipefd) < 0)
	{
		ft_printf("Pipe could not be initialised");
		exit(0);
	}
	p1 = fork();
	if (p1 < 0)
	{
		ft_printf("could not fork");
		exit(0);
	}
	if (p1 == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
		if (execute_cmd(parsed, g_envv) <= 0)//execvp(parsed[0], parsed) < 0)
		{
			ft_printf("\nCould not execute cmd 1");
			exit(1);
		}
	}
	else
	{
	// /	wait(NULL);
		p2 = fork();
		if (p2 < 0)
		{
			ft_printf("Could not fork");
			exit(0);
		}
		if (p2 == 0)
		{
			close(pipefd[1]);
			dup2(pipefd[0], STDIN_FILENO);
			close(pipefd[0]);
			if (execvp(parsedpipe[0], parsedpipe) < 0)
			{
				ft_printf("\nCould Not execute cmd 2");
				exit(0);
			}
		}
		else
		{
			wait(NULL);
			return ;
		}
	}
}

int		ft_ispipe(int c)
{
	return (c == '|');
}

void	getpipe(char *line)
{
	char	**piped;
	char	**arg1;
	char	**arg2;

	piped = ft_strsplit_f(line, ft_ispipe);
	arg1 = ft_strsplit_f(piped[0], ft_isspace);
	arg2 = ft_strsplit_f(piped[1], ft_isspace);
	execpipe(arg1, arg2);
	free_strptr(piped);
	free_strptr(arg1);
	free_strptr(arg2);
}

int		main(int argc, char **argv, char **env)
{
	char	**args;
	char	*line;
	int		status;

	status = 1;
	if (argv && argc > 1)
		return (0);
	init_env(env);
	while (status)
	{
		ft_printf("$>");
		line = NULL;
		get_my_line(1, &line);
		args = ft_strsplit_f(line, ft_isspace);
		if (ft_strindex(line, '|') >= 0)
			getpipe(line);
		else
			status = execute_cmd(args, g_envv);
		free(line);
		free_strptr(args);
	}
	return (0);
}
