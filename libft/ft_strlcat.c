/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngweny <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 13:29:20 by bngweny           #+#    #+#             */
/*   Updated: 2018/05/31 13:07:20 by bngweny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incl/libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	size_t srclen;
	size_t dstlen;
	size_t i;

	i = -1;
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (size != 0 && size - 1 > dstlen)
	{
		while (++i < size - dstlen - 1)
		{
			dst[dstlen + i] = src[i];
		}
		dst[dstlen + i] = '\0';
	}
	else
		dstlen = size;
	return (dstlen + srclen);
}
