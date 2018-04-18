/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_condition.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 20:31:52 by ytuz              #+#    #+#             */
/*   Updated: 2018/04/15 14:42:41 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	skip_until_next_condition(t_run *run_numbers)
{
	char	*current_position;

	current_position = run_numbers->command_head;
	while (*current_position != 0 && ft_strchr(";|&", current_position == 0))
		current_position = get_next_word(current_position);
	run_numbers->command_head = current_position;
}

void		run_condition(t_run *run_numbers)
{
	run_numbers->command_head = skip_spaces(run_numbers->command_head);
	while (*(run_numbers->command_head) != 0 &&
			*(run_numbers->command_head) != ';')
	{
		if (is_word_equal(run_numbers->command_head, "&&") == TRUE
			&& run_numbers->last_process_status == SUCCESS)
			run_pipe(run_numbers);
		else if (is_word_equal(run_numbers->command_head, "||") == TRUE
				&& run_numbers->last_process_status == FAILURE)
			run_pipe(run_numbers);
		else if (last_process_status == 1)
			run_pipe(run_numbers);
		else
			skip_until_next_condition(run_numbers);
	}
}
