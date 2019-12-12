/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngweny <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 11:32:31 by bngweny           #+#    #+#             */
/*   Updated: 2018/06/04 16:23:30 by bngweny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incl/libft.h"

char				*ft_strstr(const char *big, const char *little)
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
			if (little[count] != big[i + count])
				break ;
			if (little[count + 1] == '\0')
				return (char*)(big + i);
		}
	}
	return (0);
}
