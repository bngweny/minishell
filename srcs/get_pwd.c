/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngweny <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 15:44:32 by bngweny           #+#    #+#             */
/*   Updated: 2018/09/05 14:01:00 by bngweny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_cd(char *p[2], char *path)
{
	int		i;
	char	pwd[4096];

	i = chdir(p[1]);
	if (i < 0)
	{
		ft_printf("cd: no such file or directory: %s\n", path);
		return (i);
	}
	getcwd(pwd, 4096);
	change_env("OLDPWD", ft_strdup(p[0]));
	change_env("PWD", ft_strdup(pwd));
	free(path);
	return (i);
}

char	*get_home(char *path)
{
	char	*temp;

	temp = ft_strdup(path);
	free(path);
	path = ft_strjoinfree(ft_strjoin(ft_getenv("HOME"), "/"),
			ft_strchr(temp, '~') + 2);
	free(temp);
	return (path);
}

int		change_dir(char *path)
{
	char	*p[2];

	if (path)
		path = ft_strdup(path);
	if (path && *path == '~')
		path = get_home(path);
	if (!path)
	{
		p[0] = ft_getenv("PWD");
		p[1] = ft_getenv("HOME");
	}
	else if (!ft_strcmp(path, "-"))
	{
		p[0] = ft_getenv("PWD");
		p[1] = ft_getenv("OLDPWD");
		ft_printf("%s\n", p[1]);
	}
	else
	{
		p[0] = ft_getenv("PWD");
		p[1] = path;
	}
	return (check_cd(p, path));
}

char	*get_binpath(char *cmd)
{
	int				i;
	char			**bins;
	struct stat		buf;
	char			*path;

	if (lstat(cmd, &buf) == 0)
		return (ft_strdup(cmd));
	bins = ft_strsplit(ft_getenv("PATH"), ':');
	i = 0;
	if (bins)
	{
		while (bins[i])
		{
			path = ft_strjoinfree(ft_strjoinfree(ft_strdup(bins[i]), "/"), cmd);
			if (lstat(path, &buf) == 0)
			{
				free_strptr(bins);
				return (path);
			}
			free(path);
			i++;
		}
	}
	free_strptr(bins);
	return (0);
}
