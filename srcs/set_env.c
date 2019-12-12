/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngweny <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 15:45:21 by bngweny           #+#    #+#             */
/*   Updated: 2018/09/06 10:51:39 by bngweny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(char *name)
{
	int		i;

	i = ft_getenvindex(name);
	if (i > -1)
		return (ft_strchr(g_envv[i], '=') + 1);
	return (NULL);
}

void	new_env(char **args)
{
	int		i;
	char	**nenv;

	if (!(nenv = (char **)(malloc(sizeof(char *) *
		(get_envv_len(g_envv) + 2)))))
		return ;
	i = 0;
	while (g_envv[i])
	{
		nenv[i] = ft_strdup(g_envv[i]);
		i++;
	}
	if (args[2])
		nenv[i] = ft_strjoinfree(ft_strjoin(args[1], "="), args[2]);
	else
		nenv[i] = ft_strjoin(args[1], "=");
	nenv[i + 1] = NULL;
	free_strptr(g_envv);
	g_envv = nenv;
}

void	set_env(char **args)
{
	int		i;
	char	*path;

	if (args && args[1])
	{
		i = ft_getenvindex(args[1]);
		if (i >= 0)
		{
			path = ft_strsub(g_envv[i], 0, ft_strindex(g_envv[i], '=') + 1);
			free(g_envv[i]);
			if (args[2])
				g_envv[i] = ft_strjoinfree(path, args[2]);
			else
				g_envv[i] = path;
		}
		else
			new_env(args);
	}
	else
		print_evv(g_envv);
}
