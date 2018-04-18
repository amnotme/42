/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 07:05:45 by asarandi          #+#    #+#             */
/*   Updated: 2018/04/06 07:17:03 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft.h"

void	display_shell_prompt(void)
{
	ft_printf(STDOUT_FILENO, "%s", SHELL_PROMPT);
	return ;
}

void	display_shell_quote_prompt(void)
{
	ft_printf(STDOUT_FILENO, "%s", SHELL_QUOTE_PROMPT);
	return ;
}

void	reprint_input(t_shell *sh)
{
	int	move_left;

	ft_putstr(sh->carriage_return);
	ft_putstr(sh->clear_down);
	display_shell_prompt();
	ft_printf(STDOUT_FILENO, sh->buffer);
	move_left = ft_strlen(sh->buffer) - sh->buf_i;
	while (move_left--)
		ft_putstr(sh->cursor_move_left);
	return ;
}

void	insert_key_into_buffer(t_shell *sh)
{
	size_t	size;

	if (sh->buffer[sh->buf_i] != 0)
	{
		size = sh->input_size;
		while (size > sh->buf_i)
		{
			sh->buffer[size] = sh->buffer[size - 1];
			size--;
		}
	}
	sh->buffer[sh->buf_i++] = sh->keycode[0];
	sh->input_size++;
	reprint_input(sh);
	return ;
}

void	end_of_input(t_shell *sh)
{
	if (ft_strlen(sh->buffer) > 0)
		(void)history_append_to_file(sh);
	(void)ft_printf(STDOUT_FILENO, "\n");
	return ;
}
