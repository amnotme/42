/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 20:36:32 by ytuz              #+#    #+#             */
/*   Updated: 2018/04/14 22:43:14 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	run_pipe(t_run *run_numbers)
{
	while (*(run_numbers->command_head) != 0 &&
			*(run_numbers->command_head) != ';' &&
			is_conditional(run_numbers->command_head) == FALSE)
	{
		run_stream(run_numbers);
		if (*(run_numbers->command_head) == '|')
		{
			run_numbers->is_pipe = 1;
			run_numbers->command_head++;
		}
	}
}
