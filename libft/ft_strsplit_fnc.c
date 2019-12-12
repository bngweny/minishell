/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngweny <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:50:00 by bngweny           #+#    #+#             */
/*   Updated: 2018/09/05 14:06:04 by bngweny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incl/libft.h"

static int	g_w(char const *s, int (cmp)(int c))
{
	int nb_words;
	int i;

	i = 0;
	nb_words = 0;
	while (s && *(s + i))
	{
		while (*(s + i) && cmp(*(s + i)))
			i++;
		if (*(s + i))
			nb_words++;
		while (*(s + i) && !cmp(*(s + i)))
			i++;
	}
	return (nb_words);
}

char		**ft_strsplit_f(char const *s, int (cmp)(int c))
{
	size_t		start;
	size_t		end;
	char		**ptr;
	int			i;

	start = 0;
	end = 0;
	i = 0;
	ptr = NULL;
	if (!s)
		return (ptr);
	if (!(ptr = (char **)ft_memalloc(sizeof(char *) * (g_w(s, cmp) + 1))))
		return (0);
	while (g_w(s, cmp) - i)
	{
		while (s && *(s + start) && cmp(*(s + start)))
			start++;
		while (s && *(s + start + end) && !cmp(*(s + start + end)))
			end++;
		ptr[i++] = ft_strsub(s, start, end);
		start += end;
		end = 0;
	}
	ptr[i] = NULL;
	return (ptr);
}
