/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngweny <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 11:33:47 by bngweny           #+#    #+#             */
/*   Updated: 2018/06/17 14:51:56 by bngweny          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incl/get_next_line.h"

char			*ft_strjoing(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(s3 = (char *)malloc(sizeof(char) * ft_strlen(s1)
					+ ft_strlen(s2) + 1)))
		return (0);
	while (s1[i] && s1[i] != '\n')
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j] && s2[j] != '\n')
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = '\0';
	ft_strdel(&s1);
	return (s3);
}

static t_list	*get_file(t_list **file, int fd)
{
	t_list	*tmp;

	tmp = *file;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(file, tmp);
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	char			*buf;
	static t_list	*file;
	int				ret;
	t_list			*cur;

	buf = ft_strnew(BUFF_SIZE);
	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	cur = get_file(&file, fd);
	*line = ft_strnew(1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		cur->content = ft_strjoin(cur->content, buf);
		if (ft_strchr(buf, '\n'))
			break ;
		ft_strclr(buf);
	}
	if (ret < BUFF_SIZE && !ft_strlen(cur->content))
		return (0);
	*line = ft_strjoing(*line, cur->content);
	if (ft_strlen(*line) < ft_strlen(cur->content))
		cur->content += ((int)ft_strlen(*line) + 1);
	else
		ft_strclr(cur->content);
	return (1);
}

int				get_my_line(const int fd, char **line)
{
	char	*buf;
	int		ret;

	buf = ft_strnew(BUFF_SIZE);
	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	*line = ft_strnew(1);
	ret = read(fd, buf, BUFF_SIZE);
	if (ret < BUFF_SIZE && !ft_strlen(buf))
		return (0);
	*line = ft_strjoing(*line, buf);
	free(buf);
	return (1);
}
