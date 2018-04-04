/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_ioux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:52:30 by asarandi          #+#    #+#             */
/*   Updated: 2017/11/12 00:49:31 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	format_integer(t_placeholder *ph)
{
	(*ph).char_count = ft_strlen((char *)(*ph).output);
	add_precision(ph);
	if ((*ph).flags & FLAG_ZERO)
		add_width(ph);
	if (((*ph).flags & FLAG_PLUS) && (is_signed((*ph).type)))
		flag_plus(ph);
	else if ((*ph).sign == '-')
		string_prefix(ph, "-");
	if ((*ph).flags & FLAG_SPACE)
		flag_space(ph);
	add_width(ph);
}

void	format_octal(t_placeholder *ph)
{
	(*ph).char_count = ft_strlen((char *)(*ph).output);
	add_precision(ph);
	if ((*ph).flags & FLAG_HASHTAG)
	{
		if ((*ph).output[0] != '0')
			string_prefix(ph, "0");
	}
	add_width(ph);
}

void	format_hex(t_placeholder *ph)
{
	(*ph).char_count = ft_strlen((char *)(*ph).output);
	add_precision(ph);
	if (((*ph).flags & FLAG_HASHTAG) && ((*ph).n != 0))
	{
		if ((*ph).flags & FLAG_ZERO)
		{
			add_width(ph);
			string_prefix(ph, "0x");
		}
		else
			string_prefix(ph, "0x");
	}
	add_width(ph);
	if ((*ph).type == 'X')
		ft_strtoupper((char *)(*ph).output);
}

void	format_unsigned_int(t_placeholder *ph)
{
	(*ph).char_count = ft_strlen((char *)(*ph).output);
	add_precision(ph);
	add_width(ph);
}
