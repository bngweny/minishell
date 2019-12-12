/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngweny <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:44:21 by bngweny           #+#    #+#             */
/*   Updated: 2018/06/04 14:52:33 by bngweny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incl/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *out;
	t_list *temp;

	if (!lst || !(temp = ft_lstnew(NULL, 0)))
		return (0);
	out = f(lst);
	temp = out;
	while (lst->next)
	{
		lst = lst->next;
		out->next = f(lst);
		out = out->next;
	}
	return (temp);
}
