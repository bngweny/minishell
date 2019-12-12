/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strhelp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngweny <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:08:50 by bngweny           #+#    #+#             */
/*   Updated: 2018/09/04 17:09:10 by bngweny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_strindex(char *str, char c)
{
	int		i;

	i = 0;
	if (str)
		while (str[i])
		{
			if (str[i] == c)
				return (i);
			i++;
		}
	return (-1);
}

void	free_strptr(char **ptr)
{
	int		i;

	i = 0;
	if (ptr)
		while (ptr[i])
		{
			free(ptr[i]);
			i++;
		}
	free(ptr);
}

char	*ft_strjoinfree(char *s1, char const *s2)
{
	char		*s3;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	s3 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	while (s1[i])
	{
		s3[i] = s1[i];
		i += 1;
	}
	while (s2[j])
	{
		s3[i] = s2[j];
		i += 1;
		j += 1;
	}
	s3[i] = '\0';
	free(s1);
	return (s3);
}
