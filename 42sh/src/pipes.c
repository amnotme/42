/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 21:09:07 by asarandi          #+#    #+#             */
/*   Updated: 2018/04/18 00:54:54 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft.h"

int		*group_process_make_pipes(t_process **group, int *i, int *count)
{
	int	*pipes;

	*i = 0;
	while (group[*i] != NULL)
		(*i)++;
	*count = *i;
	pipes = ft_memalloc((*count) * 2 * sizeof(int));
	*i = 0;
	while (*i < *count - 1)
	{
		pipe(pipes + ((*i) * 2));
		(*i)++;
	}
	(*i) = 0;
	return (pipes);
}

int		group_process_close_pipes(t_process **group, int *pipes, int count)
{
	int	i;

	i = 0;
	while (i < count - 1)
	{
		close(pipes[i * 2]);
		close(pipes[(i * 2) + 1]);
		i++;
	}
	free(pipes);
	i = 0;
	while (group[i] != NULL)
	{
		if (group[i]->fd0 != 0)
			close(group[i]->fd0);
		if (group[i]->fd1 != 0)
			close(group[i]->fd1);
		i++;
	}
	return (0);
}

void	group_process_destroy(t_process **group)
{
	int	i;

	i = 0;
	while (group[i] != NULL)
	{
		(void)process_destroy(group[i]);
		i++;
	}
	free(group);
	return ;
}

int		group_process_wait(t_process **group)
{
	int i;
	int pid;
	int	status;

	pid = 0;
	status = 0;
	while ((pid = wait(&status)) != -1)
	{
		i = 0;
		while (group[i])
		{
			if (group[i]->pid == pid)
			{
				group[i]->exit_code = WEXITSTATUS(status);
				break ;
			}
			i++;
		}
	}
	return (status);
}
