/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngweny <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 09:30:06 by bngweny           #+#    #+#             */
/*   Updated: 2018/06/01 11:15:22 by bngweny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incl/libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
