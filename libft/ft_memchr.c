/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngweny <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 11:36:29 by bngweny           #+#    #+#             */
/*   Updated: 2018/06/04 16:49:14 by bngweny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incl/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned long	count;
	unsigned char	*str;

	count = 0;
	str = (unsigned char *)s;
	while (count < n)
	{
		if (*str == (unsigned char)c)
		{
			return (str);
		}
		count++;
		str++;
	}
	return (0);
}
