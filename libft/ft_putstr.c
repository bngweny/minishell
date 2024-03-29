/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngweny <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 09:47:35 by bngweny           #+#    #+#             */
/*   Updated: 2018/05/28 09:50:58 by bngweny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incl/libft.h"

void	ft_putstr(char const *s)
{
	while (*s != '\0')
	{
		write(1, s, 1);
		s++;
	}
}
