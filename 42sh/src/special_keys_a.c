/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_keys_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 05:16:43 by asarandi          #+#    #+#             */
/*   Updated: 2018/04/06 08:00:38 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft.h"

void	check_special_keys(t_shell *sh)
{
	int			i;
	const char	*key;
	int			len;
	const char	*special_keys[] = {KEY_UP_ARROW, KEY_DOWN_ARROW, KEY_LEFT_ARROW,
		KEY_RIGHT_ARROW, KEY_BACKSPACE, KEY_DELETE, KEY_CTRL_A, KEY_CTRL_E,
		KEY_CTRL_K, KEY_CTRL_L, KEY_TAB};
	static void	(*special_key_functions[]) (t_shell *) = {
	&key_up_arrow_function, &key_down_arrow_function, &key_left_arrow_function,
	&key_right_arrow_function, &key_backspace_function, &key_delete_function,
	&key_ctrl_a_function, &key_ctrl_e_function, &key_ctrl_k_function,
	&key_ctrl_l_function, &key_tab_function };

	i = 0;
	while (i < NUM_SPECIAL_KEYS)
	{
		key = special_keys[i];
		len = ft_strlen(key);
		if (ft_strncmp(key, sh->keycode, len) == 0)
		{
			(void)ft_bzero(sh->keycode, 9);
			return (special_key_functions[i](sh));
		}
		i++;
	}
	return ;
}

void	key_left_arrow_function(t_shell *sh)
{
	if (sh->buf_i > 0)
	{
		sh->buf_i--;
		ft_putstr(sh->cursor_move_left);
	}
	return ;
}

void	key_right_arrow_function(t_shell *sh)
{
	if (sh->buf_i < sh->input_size)
	{
		sh->buf_i++;
		ft_putstr(sh->cursor_move_right);
	}
	return ;
}

void	key_backspace_function(t_shell *sh)
{
	size_t	tempo;

	if (sh->buf_i > 0)
	{
		key_left_arrow_function(sh);
		tempo = sh->buf_i;
		while (tempo < sh->input_size)
		{
			sh->buffer[tempo] = sh->buffer[tempo + 1];
			tempo++;
		}
		sh->buffer[tempo] = 0;
		sh->input_size--;
		reprint_input(sh);
	}
	return ;
}

void	key_delete_function(t_shell *sh)
{
	size_t	tempo;

	if (sh->input_size > sh->buf_i)
	{
		tempo = sh->buf_i;
		while (tempo < sh->input_size)
		{
			sh->buffer[tempo] = sh->buffer[tempo + 1];
			tempo++;
		}
		sh->buffer[tempo] = 0;
		sh->input_size--;
		reprint_input(sh);
	}
	return ;
}
