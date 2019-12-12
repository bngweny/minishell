/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngweny <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 11:51:25 by bngweny           #+#    #+#             */
/*   Updated: 2018/05/31 13:21:43 by bngweny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incl/libft.h"

char	*ft_strnew(size_t size)
{
	char			*str;

	if (!(str = (char *)(malloc(sizeof(char) * size + 1))))
		return (0);
	ft_bzero(str, ft_strlen(str));
	return (str);
}
