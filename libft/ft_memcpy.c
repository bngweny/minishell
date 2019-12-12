/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngweny <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:00:02 by bngweny           #+#    #+#             */
/*   Updated: 2018/06/02 10:32:33 by bngweny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incl/libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	const char	*s;
	char		*d;
	size_t		count;

	count = 0;
	s = src;
	d = dst;
	while (n-- > 0)
	{
		d[count] = s[count];
		count++;
	}
	return (d);
}
