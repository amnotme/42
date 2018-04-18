/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_stream.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 19:27:30 by ytuz              #+#    #+#             */
/*   Updated: 2018/04/14 23:11:01 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	close_three(int first_fd, int second_fd, int third_fd)
{
	close(first_fd);
	close(second_fd);
	close(third_fd);
}

static void	dup_three(int first_fd, int second_fd, int third_fd)
{
	dup(first_fd);
	dup(second_fd);
	dup(third_fd);
}

static int	is_numbered_redirect(char *word_head)
{
	if (ft_strnequ(word_head, "0<", 2) == TRUE ||
		ft_strnequ(word_head, "1>", 2) == TRUE ||
		ft_strnequ(word_head, "2>", 2) == TRUE)
		return (TRUE);
	return (FALSE);
}

void		run_stream(t_run *run_numbers)
{
	char	*parser;

	dup_three(0, 1, 2);
	parser = run_numbers->command_head;
	while (*parser != 0 && ft_strchr("><;|", *parser == 0)
			&& check_numbered_redirect(parser) == FALSE &&
			is_conditional(parser) == FALSE)
		parser = get_next_word(command_end);
	run_numbers->command_end = parser;
	redirect(run_numbers);
	run_numbers->last_process_status = execute(run_numbers);
	close_three(0, 1, 2);
	run_numbers->command_head = run_numbers->stream_end;
}
