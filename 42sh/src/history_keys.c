/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 05:20:39 by asarandi          #+#    #+#             */
/*   Updated: 2018/04/06 07:00:22 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft.h"

void	key_up_arrow_function(t_shell *sh)
{
	char	*result;
	int		k;

	if (sh->history == NULL)
		return ;
	if ((sh->history_i == 0) && (sh->partial_input == NULL))
		sh->partial_input = ft_strdup(sh->buffer);
	if (sh->history_i < sh->history_count)
		sh->history_i++;
	k = sh->history_count - sh->history_i;
	result = sh->history[k];
	if (ft_strlen(result) < sh->bufsize)
	{
		ft_bzero(sh->buffer, sh->bufsize);
		(void)ft_strcpy(sh->buffer, result);
		sh->buf_i = ft_strlen(sh->buffer);
		sh->input_size = sh->buf_i;
		reprint_input(sh);
	}
	return ;
}

void	restore_partial_input(t_shell *sh)
{
	ft_bzero(sh->buffer, sh->bufsize);
	(void)ft_strcpy(sh->buffer, sh->partial_input);
	free(sh->partial_input);
	sh->partial_input = NULL;
	sh->buf_i = ft_strlen(sh->buffer);
	sh->input_size = sh->buf_i;
	reprint_input(sh);
	return ;
}

void	key_down_arrow_function(t_shell *sh)
{
	char	*result;
	int		k;

	if ((sh->history == NULL) || (sh->history_i == 0))
		return ;
	if (sh->history_i > 0)
		sh->history_i--;
	if (sh->history_i == 0)
		return (restore_partial_input(sh));
	k = sh->history_count - sh->history_i;
	result = sh->history[k];
	if (ft_strlen(result) < sh->bufsize)
	{
		ft_bzero(sh->buffer, sh->bufsize);
		(void)ft_strcpy(sh->buffer, result);
		sh->buf_i = ft_strlen(sh->buffer);
		sh->input_size = sh->buf_i;
		reprint_input(sh);
	}
	return ;
}
