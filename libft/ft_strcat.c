/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngweny <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 12:00:45 by bngweny           #+#    #+#             */
/*   Updated: 2018/05/30 11:06:14 by bngweny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incl/libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	int		count;
	int		count2;

	count = 0;
	count2 = 0;
	while (s1[count] != '\0')
	{
		count++;
	}
	while (s2[count2] != '\0')
	{
		s1[count++] = s2[count2++];
	}
	s1[count] = '\0';
	return (s1);
}
