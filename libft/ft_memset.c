/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngweny <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 09:24:56 by bngweny           #+#    #+#             */
/*   Updated: 2018/05/30 16:05:30 by bngweny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incl/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				count;
	unsigned char	*str;

	count = 0;
	str = (unsigned char *)b;
	while ((unsigned long)count < len)
	{
		str[count] = c;
		count++;
	}
	return (b);
}
