/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngweny <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 15:15:21 by bngweny           #+#    #+#             */
/*   Updated: 2018/06/04 15:15:23 by bngweny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incl/libft.h"

void	ft_lstdel(t_list **lst, void (*del)(void *, size_t))
{
	t_list	*ls;
	t_list	*nxt;

	ls = *lst;
	while (ls != '\0')
	{
		nxt = ls->next;
		del(ls->content, ls->content_size);
		free(ls);
		ls = nxt;
	}
	*lst = NULL;
}
