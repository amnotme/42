/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 21:08:07 by brabo-hi          #+#    #+#             */
/*   Updated: 2017/12/26 21:03:58 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_copy_end_file(char **str, char **line, int fd)
{
	if (!str[fd])
	{
		ft_memalloc(0);
		return (0);
	}
	if (!(*line = ft_memalloc(ft_strlen(str[fd]) + 1)))
		return (0);
	ft_strcat(*line, str[fd]);
	if (!ft_strlen(str[fd]))
		return (0);
	ft_strdel(&str[fd]);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	char static		*array[5000];
	char			buff[BUFF_SIZE];
	int				n;

	n = 0;
	if (fd < 0 || fd >= 5000 || !line)
		return (-1);
	*line = NULL;
	if (ft_contains_end_line(array[fd]))
	{
		if (!ft_copy_and_cut(array, line, fd))
			return (-1);
		return (1);
	}
	while ((n = read(fd, buff, BUFF_SIZE)) >= 0)
	{
		if (n == 0)
			break ;
		if (!ft_append(array, buff, fd, n))
			return (-1);
		if (ft_contains_end_line(array[fd]))
			return (ft_copy_and_cut(array, line, fd));
	}
	return (n == -1 ? -1 : ft_copy_end_file(array, line, fd));
}

int		ft_contains_end_line(char *str)
{
	while (str && *str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

int		ft_copy_and_cut(char **str, char **line, int fd)
{
	int		i;
	int		j;
	int		k;
	char	*new;

	i = 0;
	j = 0;
	k = 0;
	while (str[fd] && str[fd][i] && str[fd][i] != '\n')
		i++;
	if (!(*line = ft_memalloc(i + 1)))
		return (0);
	ft_strncat(*line, str[fd], i);
	i++;
	j = i;
	while (str[fd][j])
		j++;
	if (!(new = ft_memalloc(j - i + 1)))
		return (0);
	while (i < j)
		new[k++] = str[fd][i++];
	new[k] = '\0';
	ft_strdel(&str[fd]);
	str[fd] = new;
	return (1);
}

int		ft_append(char **str, char *buff, int fd, int size)
{
	int		size_str;
	char	*new_str;

	size_str = !str[fd] ? 0 : ft_strlen(str[fd]);
	if (!(new_str = ft_memalloc(size_str + size + 1)))
		return (0);
	if (str[fd])
	{
		ft_strncat(new_str, str[fd], size_str);
		ft_strdel(&str[fd]);
	}
	ft_strncat(new_str, buff, size);
	str[fd] = new_str;
	return (1);
}
