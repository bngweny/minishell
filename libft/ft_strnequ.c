/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngweny <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 11:57:55 by bngweny           #+#    #+#             */
/*   Updated: 2018/06/04 17:53:53 by bngweny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incl/libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!n)
		return (1);
	if (s1 && s2)
	{
		while ((*s1 && (*s1 == *s2)) && --n)
		{
			s1 += 1;
			s2 += 1;
		}
		if (!(*s1 - *s2))
			return (1);
	}
	return (0);
}
