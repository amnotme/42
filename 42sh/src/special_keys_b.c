/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_keys_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 07:07:34 by asarandi          #+#    #+#             */
/*   Updated: 2018/04/06 07:07:47 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft.h"

void	key_ctrl_a_function(t_shell *sh)
{
	sh->buf_i = 0;
	reprint_input(sh);
	return ;
}

void	key_ctrl_e_function(t_shell *sh)
{
	sh->buf_i = sh->input_size;
	reprint_input(sh);
	return ;
}

void	key_ctrl_k_function(t_shell *sh)
{
	sh->input_size = sh->buf_i;
	ft_bzero(&sh->buffer[sh->buf_i], sh->bufsize - sh->buf_i);
	ft_putstr(sh->clear_till_eol);
	reprint_input(sh);
	return ;
}

void	key_ctrl_l_function(t_shell *sh)
{
	ft_putstr(sh->clear_all);
	reprint_input(sh);
	return ;
}
