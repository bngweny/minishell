/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngweny <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 11:50:32 by bngweny           #+#    #+#             */
/*   Updated: 2018/06/01 14:16:33 by bngweny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incl/libft.h"

char				*ft_strnstr(const char *big, const char *little, size_t len)
{
	int count;
	int i;

	i = -1;
	if (little[0] == '\0')
		return (char*)(big);
	while (big[++i] != '\0')
	{
		count = -1;
		while (little[++count] != '\0')
		{
			if ((size_t)(i + count) >= len)
				break ;
			if (little[count] != big[i + count])
				break ;
			if (little[count + 1] == '\0')
				return (char*)(big + i);
		}
	}
	return (0);
}
