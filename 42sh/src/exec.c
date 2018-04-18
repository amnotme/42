/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 06:00:59 by asarandi          #+#    #+#             */
/*   Updated: 2018/04/15 14:36:45 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft.h"

int		fork_exec_wait(t_shell *sh, t_process *p, char *fullpath)
{
	if ((p->pid = fork()) == -1)
		fatal_error_message(sh, E_FORK);
	else if (p->pid == 0)
		execve(fullpath, p->argv, p->envp);
	if (waitpid(p->pid, &p->status, 0) == -1)
	{
		(void)perror(SHELL_NAME);
		return (1);
	}
	if (WIFEXITED(p->status))
		p->exit_code = WEXITSTATUS(p->status);
	return (p->exit_code);
}

int		execute_external_cmd(t_shell *sh, t_process *p)
{
	char	*path;
	char	*fullpath;

	if (is_valid_executable_file(p->argv[0]) == 1)
		return (fork_exec_wait(sh, p, p->argv[0]));
	else
	{
		if ((path = find_command_path(sh, p->argv[0])) == NULL)
		{
			(void)ft_printf(STDERR_FILENO,
					"%s: %s: command not found\n", SHELL_NAME, p->argv[0]);
			p->exit_code = 1;
			return (p->exit_code);
		}
		fullpath = dir_slash_exec(path, p->argv[0]);
		tcsetattr(STDIN_FILENO, TCSANOW, &sh->t_original);
		p->exit_code = fork_exec_wait(sh, p, fullpath);
		tcsetattr(STDIN_FILENO, TCSANOW, &sh->t_custom);
		free(path);
		free(fullpath);
	}
	return (p->exit_code);
}
