/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 13:56:13 by lhernand          #+#    #+#             */
/*   Updated: 2017/12/14 18:05:31 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char			*ft_strjoin(const char *s1, const char *s2)
{
	size_t			i;
	size_t			j;
	size_t			z;
	char			*s3;

	i = 0;
	j = 0;
	z = 0;
	while (s1[i++])
		;
	while (s2[j++])
		;
	if (!(s3 = (char *)malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	while (s3[z++])
		;
	i = 0;
	j = 0;
	z = 0;
	while (s1[i])
		s3[z++] = s1[i++];
	while (s2[j])
		s3[z++] = s2[j++];
	s3[z] = '\0';
	return (s3);
}

static char			*ft_strdup(const char *str)
{
	size_t			i;
	size_t			j;
	char			*dupped;

	i = 0;
	j = 0;
	while (str[i++])
		;
	if (!(dupped = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (dupped[j])
		dupped[j++] = '\0';
	j = 0;
	while (str[i])
		dupped[j++] = str[i++];
	dupped[j] = '\0';
	return (dupped);
}

static int			valid_line(char **stk, char **line)
{
	char		*ptr;
	char		*tmp;
	int			i;

	i = 0;
	ptr = *stk;
	while (ptr[i] != '\n')
	{
		if (ptr[i] == '\0')
			return (0);
		else
			i++;
	}
	tmp = &ptr[i];
	*tmp = '\0';
	*stk = ft_strdup(tmp + 1);
	*line = ft_strdup(ptr);
	free(ptr);
	ptr = NULL;
	return (1);
}

static int			read_file(int fd, char *hp, char **stk, char **line)
{
	int				ret;
	char			*ptr;

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

int					get_next_line(int fd, char **line)
{
	static char		*stk[DESCRIPTORS];
	char			*hp;
	int				ret;
	int				i;

	i = 0;
	if (!line || fd < 0 || fd >= DESCRIPTORS || (read(fd, stk[fd], 0) < 0) \
			|| !(hp = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	if (stk[fd])
		if (valid_line(&stk[fd], line))
			return (1);
	while (i < BUFF_SIZE)
		hp[i++] = '\0';
	ret = read_file(fd, hp, &stk[fd], line);
	free(hp);
	if (ret != 0 || stk[fd] == NULL || stk[fd][0] == '\0')
	{
		if (ret == 0 && *line)
			*line = NULL;
		return (ret);
	}
	*line = stk[fd];
	stk[fd] = NULL;
	return (1);
}
