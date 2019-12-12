/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngweny <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 15:48:02 by bngweny           #+#    #+#             */
/*   Updated: 2018/09/12 14:50:02 by bngweny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		get_envv_len(char **env)
{
	int		i;

	i = 0;
	if (env)
		while (env[i])
			i++;
	return (i);
}

void	print_evv(char **env)
{
	int		i;

	i = 0;
	if (env)
	{
		while (env[i])
		{
			ft_printf("%s\n", env[i]);
			i++;
		}
	}
}

int		ft_getenvindex(char *name)
{
	int		i;
	char	*temp;

	i = 0;
	if (g_envv)
		while (g_envv[i])
		{
			temp = ft_strsub(g_envv[i], 0, ft_strindex(g_envv[i], '='));
			if (!ft_strcmp(temp, name))
			{
				free(temp);
				return (i);
			}
			free(temp);
			i++;
		}
	return (-1);
}

void	init_env(char **tenvv)
{
	int		i;

	i = 0;
	if (!(g_envv = (char **)malloc(sizeof(char *) * get_envv_len(tenvv) + 1)))
		return ;
	while (tenvv[i])
	{
		g_envv[i] = ft_strdup(tenvv[i]);
		i++;
	}
	g_envv[i] = NULL;
}

void	change_env(char *name, char *new)
{
	int		i;
	char	*path;

	i = ft_getenvindex(name);
	if (i >= 0)
	{
		path = ft_strsub(g_envv[i], 0, ft_strindex(g_envv[i], '=') + 1);
		free(g_envv[i]);
		g_envv[i] = ft_strjoinfree(path, new);
		free(new);
	}
}
