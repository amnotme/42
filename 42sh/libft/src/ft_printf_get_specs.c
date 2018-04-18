/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_specs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 15:55:33 by asarandi          #+#    #+#             */
/*   Updated: 2017/11/11 19:37:56 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	get_placeholder_flags(char **fmt, t_placeholder *placeholder)
{
	if (**fmt == '%')
		(*fmt)++;
	while (**fmt)
	{
		if (**fmt == '#')
			(*placeholder).flags |= FLAG_HASHTAG;
		else if (**fmt == '0')
			(*placeholder).flags |= FLAG_ZERO;
		else if (**fmt == '-')
			(*placeholder).flags |= FLAG_MINUS;
		else if (**fmt == ' ')
			(*placeholder).flags |= FLAG_SPACE;
		else if (**fmt == '+')
			(*placeholder).flags |= FLAG_PLUS;
		else
			break ;
		(*fmt)++;
	}
	if ((*placeholder).flags)
		(*placeholder).have_flags = 1;
	return ;
}

void	get_placeholder_width(char **fmt, va_list *ap, t_placeholder *ph)
{
	while ((is_digit(**fmt)) || (**fmt == '*'))
	{
		(*ph).width = 0;
		while ((**fmt >= '0') && (**fmt <= '9'))
		{
			(*ph).width = ((*ph).width * 10) + (**fmt - '0');
			(*fmt)++;
		}
		if (**fmt == '*')
		{
			(*ph).width = (int)va_arg(*ap, int);
			if ((*ph).width < 0)
			{
				(*ph).width = -(*ph).width;
				(*ph).flags |= FLAG_MINUS;
			}
			(*fmt)++;
		}
	}
	if ((*ph).width)
		(*ph).have_width = 1;
}

void	get_placeholder_precision(char **fmt, va_list *ap, t_placeholder *ph)
{
	if (**fmt != '.')
		return ;
	(*fmt)++;
	(*ph).have_precision = 1;
	if (**fmt == '*')
	{
		(*fmt)++;
		(*ph).precision = (int)va_arg(*ap, int);
		if ((*ph).precision < 0)
			(*ph).have_precision = 0;
	}
	else
	{
		while ((**fmt >= '0') && (**fmt <= '9'))
		{
			(*ph).precision = ((*ph).precision * 10) + (**fmt - '0');
			(*fmt)++;
		}
	}
	return ;
}

void	get_placeholder_length(char **fmt, t_placeholder *placeholder)
{
	if ((**fmt == 'h') && ((*(fmt))[1] == 'h'))
		(*placeholder).length = sizeof(char) * CHAR_BIT;
	else if (**fmt == 'h')
		(*placeholder).length = sizeof(short) * CHAR_BIT;
	else if ((**fmt == 'l') && ((*(fmt))[1] == 'l'))
		(*placeholder).length = sizeof(long long) * CHAR_BIT;
	else if (**fmt == 'l')
		(*placeholder).length = sizeof(long) * CHAR_BIT;
	else if (**fmt == 'j')
		(*placeholder).length = sizeof(intmax_t) * CHAR_BIT;
	else if (**fmt == 't')
		(*placeholder).length = sizeof(ptrdiff_t) * CHAR_BIT;
	else if (**fmt == 'z')
		(*placeholder).length = sizeof(size_t) * CHAR_BIT;
	if ((**fmt == 'h') && ((*(fmt))[1] == 'h'))
		(*fmt)++;
	else if ((**fmt == 'l') && ((*(fmt))[1] == 'l'))
		(*fmt)++;
	if ((*placeholder).length)
		(*fmt)++;
	return ;
}

void	get_placeholder_type(char **fmt, t_placeholder *ph)
{
	const char	*valid_types = "dDiuUoOxXpcCsSfFnkb";
	int			i;

	i = 0;
	(*ph).type = **fmt;
	(*ph).invalid = 1;
	while (valid_types[i])
	{
		if (**fmt == valid_types[i])
		{
			(*ph).invalid = 0;
			break ;
		}
		i++;
	}
	if (**fmt)
		(*fmt)++;
	return ;
}
