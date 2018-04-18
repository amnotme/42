/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:32:47 by ytuz              #+#    #+#             */
/*   Updated: 2018/04/15 14:41:06 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	run_input(char ***env, char *input_head)
{
	t_run	*run_numbers;

	input_head = skip_spaces(input_head);
	run_numbers = MEMALLOC(run_numbers, 1);
	run_numbers->env = env;
	run_numbers->input_head = input_head;
	pipe(run_numbers->pipe);
	run_numbers->command_head = run_numbers->input_head;
	run_numbers->last_process_status = 1;
	while (run_numbers->command_head != 0)
	{
		run_job(run_numbers);
	}
	free_run_numbers(run_numbers);
}
