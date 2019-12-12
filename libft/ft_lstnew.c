/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngweny <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 13:26:08 by bngweny           #+#    #+#             */
/*   Updated: 2018/06/17 13:36:01 by bngweny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incl/libft.h"

t_list	*ft_lstnew(void const *c, size_t c_size)
{
	t_list	*out;

	if (!(out = (t_list*)(malloc(sizeof(t_list) * c_size))))
		return (0);
	if (!c)
	{
		out->content = NULL;
		out->content_size = 0;
	}
	else
	{
		if (!(out->content = (void *)malloc(c_size)))
			return (NULL);
		ft_memcpy(out->content, c, c_size);
		out->content_size = c_size;
	}
	out->next = NULL;
	return (out);
}
