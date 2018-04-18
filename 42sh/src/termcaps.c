/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 05:27:41 by asarandi          #+#    #+#             */
/*   Updated: 2018/04/06 06:56:42 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft.h"

void	termios_save_settings(t_shell *sh)
{
	if (tcgetattr(STDIN_FILENO, &sh->t_original) == -1)
		return (fatal_error_message(sh, "tcgetattr() failed"));
	sh->t_custom = sh->t_original;
	sh->t_custom.c_cc[VMIN] = 1;
	sh->t_custom.c_cc[VTIME] = 0;
	sh->t_custom.c_lflag &= ~(ICANON | ECHO);
	if (tcsetattr(STDIN_FILENO, TCSANOW, &sh->t_custom) == -1)
		return (fatal_error_message(sh, "tcsetattr() failed"));
	sh->custom_terminal = 1;
	return ;
}

void	termios_restore_settings(t_shell *sh)
{
	if (sh->custom_terminal == 1)
		tcsetattr(STDIN_FILENO, TCSANOW, &sh->t_original);
	return ;
}

void	terminal_init(t_shell *sh)
{
	char	buf[1024];
	char	*term;

	term = kv_array_get_key_value(sh->envp, "TERM");
	if (term == NULL)
		term = "xterm";
	tgetent(buf, term);
	sh->carriage_return = tgetstr("cr", NULL);
	sh->cursor_move_left = tgetstr("le", NULL);
	sh->cursor_move_right = tgetstr("nd", NULL);
	sh->cursor_move_down = tgetstr("do", NULL);
	sh->cursor_move_up = tgetstr("up", NULL);
	sh->clear_till_eol = tgetstr("ce", NULL);
	sh->clear_all = tgetstr("cl", NULL);
	sh->clear_down = tgetstr("cd", NULL);
	(void)termios_save_settings(sh);
	return ;
}
