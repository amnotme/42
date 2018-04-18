/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:57:49 by asarandi          #+#    #+#             */
/*   Updated: 2017/11/13 14:00:38 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	format_pointer(t_placeholder *ph)
{
	(*ph).char_count = ft_strlen((char *)(*ph).output);
	add_precision(ph);
	(*ph).char_count = ft_strlen((char *)(*ph).output);
	if ((*ph).flags & FLAG_ZERO)
		add_width(ph);
	string_prefix(ph, "0x");
	(*ph).char_count = ft_strlen((char *)(*ph).output);
	add_width(ph);
}

void	format_invalid(t_placeholder *ph)
{
	add_precision(ph);
	add_width(ph);
	(*ph).char_count = ft_strlen((char *)(*ph).output);
}

void	format_output(char type, t_placeholder *ph)
{
	if ((type == 'd') || (type == 'i') || (type == 'D'))
		format_integer(ph);
	else if ((type == 'o') || (type == 'O'))
		format_octal(ph);
	else if ((type == 'x') || (type == 'X'))
		format_hex(ph);
	else if (type == 's')
		format_string(ph);
	else if (type == 'S')
		format_wide_string(ph);
	else if ((type == 'u') || (type == 'U') || (type == 'b'))
		format_unsigned_int(ph);
	else if (type == 'c')
		format_char(ph);
	else if (type == 'C')
		format_wide_char(ph);
	else if (type == 'p')
		format_pointer(ph);
	else if ((type == 'f') || (type == 'F'))
		format_double(ph);
	else
		format_invalid(ph);
}

void	parse_placeholder(char **fmt, va_list *ap, t_placeholder *ph)
{
	(*ph).location = *fmt;
	get_placeholder_flags(fmt, ph);
	get_placeholder_width(fmt, ap, ph);
	if ((*ph).flags & FLAG_MINUS)
		(*ph).flags &= ~(1 << 1);
	get_placeholder_precision(fmt, ap, ph);
	get_placeholder_length(fmt, ph);
	get_placeholder_type(fmt, ph);
	if (is_numeric((*ph).type))
	{
		(*ph).n = (uintmax_t)va_arg(*ap, uintmax_t);
		if ((is_deprecated((*ph).type)) || ((*ph).length == 0))
			(*ph).length = get_default_length((*ph).type);
		if ((*ph).length < get_default_length((*ph).type))
			trim_bits(ph);
		make_numeric_output(ph);
	}
	else
		make_non_numeric(ph, ap);
	format_output((*ph).type, ph);
}

int		init_placeholder(t_placeholder *ph)
{
	(*ph).flags = 0;
	(*ph).have_flags = 0;
	(*ph).width = 0;
	(*ph).have_width = 0;
	(*ph).precision = 0;
	(*ph).have_precision = 0;
	(*ph).length = 0;
	(*ph).have_length = 0;
	(*ph).type = 0;
	(*ph).have_type = 0;
	(*ph).n = 0;
	(*ph).sign = 0;
	(*ph).invalid = 0;
	(*ph).location = 0;
	(*ph).output = 0;
	(*ph).float_prefix = 0;
	(*ph).float_suffix = 0;
	(*ph).char_count = 0;
	return (0);
}
