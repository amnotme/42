/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 20:57:18 by lhernand          #+#    #+#             */
/*   Updated: 2017/12/13 03:29:39 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_strdup(const char *s1)
{
	size_t		i;
	char		*s2;

	i = 0;
	while (s1[i])
		i++;
	if (!(s2 = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

static char		*ft_strjoin(const char *s1, const char *s2)
{
	int			i;
	int			j;
	int			z;
	char		*s3;

	i = 0;
	j = 0;
	z = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	if (!s1 || !s2 || !(s3 = (char *)malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		s3[z++] = s1[i++];
	while (s2[j])
		s3[z++] = s2[j++];
	s3[z] = '\0';
	return (s3);
}

static int		valid_line(char **stk, char **line)
{
	char		*chars_in_stk;
	char		*tmp_stk;
	int			pos;

	pos = 0;
	chars_in_stk = *stk;
	while (chars_in_stk[pos] != '\n')
	{
		if (chars_in_stk[pos] == '\0')
			return (0);
		pos++;
	}
	tmp_stk = &chars_in_stk[pos];
	*tmp_stk = '\0';
	*line = ft_strdup(*stk);
	*stk = ft_strdup(tmp_stk + 1);
	return (1);
}

static int		read_file(int fd, char *hp, char **stk, char **line)
{
	int			ret;
	char		*ptr;

	while ((ret = read(fd, hp, BUFF_SIZE)) > 0)
	{
		hp[ret] = '\0';
		if (*stk)
		{
			ptr = *stk;
			*stk = ft_strjoin(ptr, hp);
			free(ptr);
			ptr = NULL;
		}
		else
			*stk = ft_strdup(hp);
		if (valid_line(stk, line))
			break ;
	}
	if (ret > 0)
		return (1);
	return (ret);
}

int				get_next_line(const int fd, char **line)
{
	static char *stk[DESCRIPTORS];
	char		*hp;
	int			ret;
	int			i;

	i = 0;
	if (!(hp = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)) || fd < 0 || !line
			|| fd > DESCRIPTORS || (read(fd, stk[fd], 0) < 0))
		return (-1);
	if (stk[fd])
		if (valid_line(&stk[fd], line))
			return (1);
	while (i < BUFF_SIZE)
		hp[i++] = '\0';
	ret = read_file(fd, hp, &stk[fd], line);
	free(hp);
	if (stk[fd][0] == '\0' || stk[fd] == NULL || ret != 0)
	{
		if ((ret == 0) && (*line))
			*line = NULL;
		return (ret);
	}
	*line = stk[fd];
	stk[fd] = NULL;
	return (1);
}
