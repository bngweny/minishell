/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngweny <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 11:44:08 by bngweny           #+#    #+#             */
/*   Updated: 2018/05/30 16:13:10 by bngweny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incl/libft.h"

void	*ft_memalloc(size_t size)
{
	void *out;

	if (!(out = malloc(size)))
		return (0);
	ft_memset(out, 0, size);
	return (out);
}
