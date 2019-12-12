/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngweny <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 11:54:39 by bngweny           #+#    #+#             */
/*   Updated: 2018/06/04 17:49:47 by bngweny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incl/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int count;

	count = 0;
	if (s && f)
		while (s[count])
		{
			f(count, &s[count]);
			count++;
		}
}
