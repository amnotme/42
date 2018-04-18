/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_numeric.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 00:42:34 by asarandi          #+#    #+#             */
/*   Updated: 2017/11/12 12:10:36 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		is_digit(char c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	else
		return (0);
}

int		is_deprecated(char type)
{
	if ((type == 'D') || (type == 'O') || (type == 'U'))
		return (1);
	return (0);
}

void	other_formats(t_placeholder *ph, va_list *ap)
{
	if ((*ph).type == 'k')
	{
		iso_time((uintmax_t)va_arg(*ap, uintmax_t));
		(*ph).output = ft_memalloc(1);
		(*ph).char_count = ft_strlen("2017-11-11T20:26:43+00:00");
	}
	else if (((*ph).type == 'f') || ((*ph).type == 'F'))
	{
		if ((*ph).have_precision == 0)
		{
			(*ph).precision = 6;
			(*ph).have_precision = 1;
		}
		get_double(ap, ph);
	}
	else
	{
		(*ph).invalid = 1;
		(*ph).output = ft_memalloc(2);
		(*ph).output[0] = (*ph).type;
		(*ph).char_count = 1;
	}
}

void	make_non_numeric(t_placeholder *ph, va_list *ap)
{
	int	*n_ptr;

	if ((*ph).type == 's')
		(*ph).output = get_string(ap, ph);
	else if ((*ph).type == 'S')
		(*ph).output = get_wide_string(ap, ph);
	else if ((*ph).type == 'C')
		(*ph).output = get_wchar(ap, ph);
	else if ((*ph).type == 'c')
		(*ph).output = get_char(ap, ph);
	else if ((*ph).type == 'n')
	{
		n_ptr = (int *)va_arg(*ap, int *);
		*n_ptr = (*ph).written;
		(*ph).output = ft_memalloc(1);
	}
	else
		other_formats(ph, ap);
}
