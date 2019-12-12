/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngweny <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 11:24:06 by bngweny           #+#    #+#             */
/*   Updated: 2018/06/12 16:32:58 by bngweny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incl/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int index;

	index = ft_strlen(s);
	while (index >= 0)
	{
		if (s[index] == (unsigned char)c)
		{
			break ;
		}
		--index;
	}
	if (index == 0)
		return ((char *)s);
	while ((*s != '\0') && (index >= 0))
	{
		++s;
		--index;
		if (index == 0)
		{
			return ((char *)s);
		}
	}
	return (NULL);
}
