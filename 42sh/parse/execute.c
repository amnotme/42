/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 22:53:19 by ytuz              #+#    #+#             */
/*   Updated: 2018/04/15 00:02:28 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	free_char_double_pointer(char **double_pointer)
{
	while (*double_pointer)
	{
		free(*double_pointer);
		double_pointer++;
	}
	free(double_pointer);
}

void		execute(t_run *run_numbers)
{
	char	**av;
	char	***env;
	char	*av_string;
	int		*status;

	status = MEMALLOC(int, 1);
	env = run_numbers->env;
	av_string = ft_struntil(run_numbers->command_head,
							run_numbers->command_end);
	av = ft_strsplit(av_string, ' ');
	free(av_string);
	if (check_functions(av, env, status) == FAILURE &&
		check_executables(av, env, status) == FAILURE)
		ft_errorf("42sh: command not found: %s\n", av[0]);
	free_char_double_pointer(av);
	if (*status != SUCCESS)
		*status = FAILURE;
	run_numbers->last_process_status = *status;
	free(status);
}
