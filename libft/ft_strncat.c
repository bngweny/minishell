/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngweny <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:16:07 by bngweny           #+#    #+#             */
/*   Updated: 2018/05/31 12:19:37 by bngweny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incl/libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	int		count;
	int		count2;

	count = ft_strlen(s1);
	count2 = 0;
	while (n-- > 0 && s2[count2] != '\0')
	{
		s1[count++] = s2[count2++];
	}
	s1[count] = '\0';
	return (s1);
}
