/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_built.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngweny <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 14:48:30 by bngweny           #+#    #+#             */
/*   Updated: 2018/09/05 15:08:43 by bngweny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_isquote(char c)
{
	return (c == '\'' || c == '\"');
}

int		print_var(char **args, int i, int j)
{
	int		k;
	char	*temp;

	k = ++j;
	while (args[i][j++])
	{
		temp = ft_strsub(args[i], k, j - k);
		if (ft_getenv(temp))
		{
			ft_printf("%s", ft_getenv(temp));
			free(temp);
			return (j + 1);
		}
		free(temp);
		if (ft_isquote(args[i][j]))
			return (j + 1);
	}
	return (j + 1);
}

void	echo_built(char **args)
{
	int		i;
	int		j;

	i = 1;
	if (args)
		while (args[i])
		{
			j = 0;
			while (args[i][j])
			{
				if (args[i][j] == '$')
					j = print_var(args, i, j);
				if (!ft_isquote(args[i][j]))
					ft_printf("%c", args[i][j]);
				j++;
			}
			i++;
			ft_printf(" ");
		}
	ft_printf("\n");
}
