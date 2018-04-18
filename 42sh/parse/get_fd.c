/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:15:18 by ytuz              #+#    #+#             */
/*   Updated: 2018/04/13 16:21:58 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	get_fd(char *file_head, int is_append, int is_write)
{
	int		fd;
	char	*file_path;
	char	*path_end;

	path_end = file_head;
	while (*path_end != 0 && *path_end != ' ' && *path_end != ';')
		path_end++;
	file_path = ft_struntil2(file_head, path_end);
	if (is_write == TRUE)
	{
		if (is_append == TRUE)
			fd = open(file_path, O_WRONLY | O_APPEND);
		else
			fd = open(file_path, O_WRONLY);
	}
	else
		fd = open(file_path, O_RDONLY);
	free(file_path);
	return (fd);
}
