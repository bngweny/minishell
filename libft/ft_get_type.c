/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngweny <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 12:44:20 by bngweny           #+#    #+#             */
/*   Updated: 2018/08/07 15:04:42 by bngweny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incl/ft_printf.h"

static void		ft_margin(t_flag lst)
{
	int i;

	i = 0;
	if (lst.flagzero && !lst.flagminus)
		while (i < lst.min - 1)
		{
			ft_buffer("0", 1, 0);
			i++;
		}
	else
		while (i < lst.min - 1)
		{
			ft_buffer(" ", 1, 0);
			i++;
		}
}

static void		ft_put100(t_flag lst)
{
	if (!lst.flagminus)
		ft_margin(lst);
	ft_buffer("%", 1, 0);
	if (lst.flagminus)
		ft_margin(lst);
}

t_flag			ft_type(va_list ap, t_flag lst)
{
	if (lst.type == '%')
		ft_put100(lst);
	if (lst.type == 'c' || lst.type == 'C')
		lst = ft_printf_putchar(ap, lst);
	if (lst.type == 's' || lst.type == 'S')
		ft_printf_string(ap, lst);
	if (lst.type == 'd' || lst.type == 'D' || lst.type == 'i')
		ft_printf_nbr(ap, lst);
	if (lst.type == 'p' || lst.type == 'x' || lst.type == 'X' ||
			lst.type == 'o' || lst.type == 'O' || lst.type == 'O' ||
				lst.type == 'u' || lst.type == 'U')
		ft_printf_base(ap, lst);
	return (lst);
}
