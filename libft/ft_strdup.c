/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngweny <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 10:26:35 by bngweny           #+#    #+#             */
/*   Updated: 2018/05/31 16:00:46 by bngweny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incl/libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*ret;
	int		count;

	len = ft_strlen(s1);
	count = 0;
	if (!(ret = (char *)(malloc(sizeof(char) * len + 1))))
		return (0);
	while (count < len)
	{
		ret[count] = s1[count];
		count++;
	}
	ret[count] = '\0';
	return (ret);
}
