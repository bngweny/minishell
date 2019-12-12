/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngweny <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 16:01:11 by bngweny           #+#    #+#             */
/*   Updated: 2018/09/05 16:46:04 by bngweny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	remove_env(int i)
{
	free(g_envv[i]);
	while (g_envv[i + 1])
	{
		g_envv[i] = ft_strdup(g_envv[i + 1]);
		free(g_envv[i + 1]);
		i++;
	}
	g_envv[i] = NULL;
}

void	unset_env(char **args)
{
	int i;

	if (args && args[1])
	{
		i = ft_getenvindex(args[1]);
		if (i >= 0)
		{
			remove_env(i);
		}
	}
	else
		ft_printf("unsetenv: Invalid Arguments\n");
}
