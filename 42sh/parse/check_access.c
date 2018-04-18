/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 07:40:41 by ytuz              #+#    #+#             */
/*   Updated: 2018/04/10 08:07:50 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	tsh_child(char *path, t_tsh_run *run_subset)
{
	if (run_subset->input_fd != 0)
	{
		close(0);
		dup2(run_subset->output_pipe[0], 0);
	}
	close(1);
	dup2(run_subset->output_pipe[1], 1);
	close(2);
	dup2(run_subset->error_pipe[1], 2);
	execve(path);
	return (SUCCESS);
}

static int	tsh_execute(char *path, t_tsh_run *run_subset)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		return (tsh_child(path, run_subset));
	}
	else
	{
		run_subset->pid = pid;
		return (tsh_parent(run_subset));
	}
}

int			tsh_check_access(char *path, unsigned int path_length,
				t_tsh_run *run_subset)
{
	char	buffer[1000];
	char	*buffer_end;

	ft_bzero(buffer, 1000);
	ft_strncpy(buffer, path, path_length);
	buffer_end = buffer + path_length - 1;
	if (*buffer_end != '/')
	{
		*(buffer_end + 1) = '/';
		buffer_end++;
	}
	while (*path != 0 && *path != ':')
	{
		*buffer_end = *path;
		buffer_end++;
		path++;
	}
	if (access(buffer, X_OK) != SUCCESS)
		return (FAILURE);
	tsh_execute(buffer, run_subset);
	return (SUCCESS);
}
