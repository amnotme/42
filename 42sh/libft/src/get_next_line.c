/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 12:10:14 by asarandi          #+#    #+#             */
/*   Updated: 2018/03/08 22:09:56 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		gnl_more_mem(char **memory, t_gnl **gnl)
{
	char	*new;

	if ((new = ft_memalloc((*gnl)->size + BUFF_SIZE)) == NULL)
		return (-1);
	ft_memcpy(new, *memory, (*gnl)->size);
	free(*memory);
	*memory = new;
	if ((read((*gnl)->fd, &new[(*gnl)->size], BUFF_SIZE)) == 0)
		(*gnl)->eof = 1;
	(*gnl)->size += BUFF_SIZE;
	return (1);
}

int		gnl_read(int fd, t_gnl **gnl, char **memory)
{
	int r;

	if ((read(fd, *memory, 0)) == -1)
		return (-1);
	if ((*memory = ft_memalloc(BUFF_SIZE)) == NULL)
		return (-1);
	if ((r = read(fd, *memory, BUFF_SIZE)) == 0)
	{
		free(*memory);
		return (0);
	}
	if ((*gnl)->mem && (fd != (*gnl)->fd))
	{
		(*gnl)->next = ft_memalloc(sizeof(t_gnl));
		if ((*gnl)->next == NULL)
			return (-1);
		(*gnl)->next->prev = (*gnl);
		(*gnl) = (*gnl)->next;
	}
	(*gnl)->mem = *memory;
	(*gnl)->size = BUFF_SIZE;
	(*gnl)->fd = fd;
	return (1);
}

int		gnl_save(char **memory, t_gnl **gnl, char **line)
{
	size_t	rsize;
	char	*mem2;

	mem2 = ft_memchr(*memory, '\n', (*gnl)->size);
	rsize = (mem2 - *memory) + 1;
	if ((*line = ft_memalloc(rsize)) == NULL)
		return (-1);
	ft_memcpy(*line, *memory, rsize - 1);
	if (((*gnl)->size > rsize) && ((*memory + rsize)[0]))
	{
		if (((*gnl)->mem = ft_memalloc((*gnl)->size - rsize)) == NULL)
			return (-1);
		ft_memcpy((*gnl)->mem, *memory + rsize, (*gnl)->size - rsize);
		(*gnl)->size -= rsize;
	}
	else
	{
		(*gnl)->mem = 0;
		(*gnl)->size = 0;
	}
	free(*memory);
	return (1);
}

int		gnl_main(char **memory, t_gnl **gnl, char **line)
{
	while ((ft_memchr(*memory, '\n', (*gnl)->size)) == NULL)
	{
		(*gnl)->mem = 0;
		*line = *memory;
		if (((*gnl)->eof) && ((*memory)[0]))
			return (1);
		else if (((*gnl)->eof) && (!(*memory)[0]))
		{
			*line = NULL;
			if ((*gnl)->size)
				free(*memory);
			(*gnl)->size = 0;
			if ((*gnl)->prev)
			{
				(*gnl)->prev->next = NULL;
				free(*gnl);
			}
			return (0);
		}
		if ((gnl_more_mem(memory, gnl)) != 1)
			return (-1);
	}
	return (gnl_save(memory, gnl, line));
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	first;
	char			*memory;
	int				tmp;
	t_gnl			*gnl;

	if ((fd == 1) || (fd == 2) || (line == NULL))
		return (-1);
	gnl = &first;
	*line = NULL;
	memory = NULL;
	while ((gnl->fd != fd) && (gnl->next))
		gnl = gnl->next;
	if ((gnl->fd == fd) && (gnl->mem))
		memory = gnl->mem;
	else if ((tmp = gnl_read(fd, &gnl, &memory)) != 1)
		return (tmp);
	gnl->eof = 0;
	gnl->fd = fd;
	return (gnl_main(&memory, &gnl, line));
}
