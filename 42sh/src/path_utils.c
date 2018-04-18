/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 05:29:17 by asarandi          #+#    #+#             */
/*   Updated: 2018/04/08 16:00:07 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft.h"

char	*dir_slash_exec(char *dir, char *cmd)
{
	char	*result;
	char	*folder;

	if (dir == NULL)
		dir = EMPTY_STRING;
	if ((ft_strlen(dir) > 0) && (dir[ft_strlen(dir) - 1] != '/'))
		folder = ft_strjoin(dir, "/");
	else
		folder = ft_strdup(dir);
	result = ft_strjoin(folder, cmd);
	free(folder);
	return (result);
}

int		is_valid_executable_file(char *filename)
{
	struct stat	st;

	if (access(filename, F_OK | X_OK) == 0)
	{
		if (stat(filename, &st) == 0)
		{
			if (S_ISREG(st.st_mode))
				return (1);
		}
	}
	return (0);
}

int		path_has_executable(char *path, char *cmd)
{
	char	*fullpath;
	int		result;

	fullpath = dir_slash_exec(path, cmd);
	result = is_valid_executable_file(fullpath);
	free(fullpath);
	return (result);
}

char	*basename(char *str)
{
	char	*result;

	result = ft_strrchr(str, '/');
	if (result == NULL)
		return (EMPTY_STRING);
	else if (result[1] == 0)
		return (EMPTY_STRING);
	return (&result[1]);
}

char	*find_command_path(t_shell *sh, char *cmd)
{
	char	**folders;
	char	*path;
	char	*result;
	int		i;

	if ((path = kv_array_get_key_value(sh->envp, "PATH")) == NULL)
		return (NULL);
	if ((folders = ft_strsplit(path, ':')) == NULL)
		fatal_error_message(sh, E_NOMEM);
	i = 0;
	result = NULL;
	while (folders[i])
	{
		if (path_has_executable(folders[i], cmd) == 1)
		{
			result = ft_strdup(folders[i]);
			break ;
		}
		i++;
	}
	destroy_char_array(folders);
	return (result);
}
