/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 05:14:52 by asarandi          #+#    #+#             */
/*   Updated: 2018/04/06 06:16:06 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft.h"

char	*history_get_item(t_shell *sh, int index)
{
	char	**history;
	int		count;
	char	*result;

	if ((history = history_array(sh)) == NULL)
		return (NULL);
	count = count_char_array(history);
	result = NULL;
	if (index <= count)
	{
		result = ft_strdup(history[count - index]);
	}
	destroy_char_array(history);
	return (result);
}

void	history_append_to_file(t_shell *sh)
{
	int		fd;
	char	*filename;

	filename = history_file_name(sh);
	fd = open(filename, O_APPEND | O_CREAT | O_WRONLY, 0644);
	free(filename);
	if (fd == -1)
		return ;
	(void)lseek(fd, 0, SEEK_END);
	(void)write(fd, sh->buffer, sh->input_size);
	(void)write(fd, "\n", 1);
	(void)close(fd);
	return ;
}

char	*history_file_name(t_shell *sh)
{
	char	*home;
	char	*fullpath;

	home = kv_array_get_key_value(sh->envp, "HOME");
	if (home == NULL)
		home = EMPTY_STRING;
	fullpath = dir_slash_exec(home, HISTORY_FILE);
	return (fullpath);
}

char	**history_array(t_shell *sh)
{
	char	*filename;
	char	*data;
	char	**array;

	filename = history_file_name(sh);
	data = file_get_contents(filename);
	free(filename);
	if (data == NULL)
		return (NULL);
	array = ft_strsplit(data, '\n');
	free(data);
	return (array);
}
