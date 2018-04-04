/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 09:21:32 by asarandi          #+#    #+#             */
/*   Updated: 2018/03/31 04:55:46 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	invalid_skip_forward(char **fmt, t_placeholder *ph)
{
	if (((*ph).invalid == 1) && ((*ph).char_count == 0))
	{
		while (**fmt)
		{
			if ((**fmt >= 9) && (**fmt <= 13))
				break ;
			else if (**fmt == ' ')
				break ;
			else
				(*fmt)++;
		}
	}
}

int		main_routine(int fd, t_cc *restrict *format, va_list *ap, int written)
{
	char			*fmt;
	t_placeholder	placeholder;

	if (*(*format + 1) == '%')
	{
		(*format)++;
		return (write(1, (*format)++, 1));
	}
	fmt = (char *)*(format);
	init_placeholder(&placeholder);
	placeholder.written = written;
	parse_placeholder(&fmt, ap, &placeholder);
	if (placeholder.char_count == 0)
		placeholder.char_count = ft_strlen((char *)placeholder.output);
	(void)(write(fd, placeholder.output, placeholder.char_count) + 1);
	free(placeholder.output);
	invalid_skip_forward(&fmt, &placeholder);
	(*format) = (char *)fmt;
	return (placeholder.char_count);
}

int		color_routine(int fd, const char *restrict *format)
{
	int	i;

	i = check_colors(fd, (char *)*format);
	if (i)
	{
		while (**format != '}')
			(*format)++;
		(*format)++;
	}
	return (i);
}

int		ft_printf(int fd, const char *restrict format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (((*format) == '{') && (*format + 1))
			count += color_routine(fd, &format);
		if ((*format == '%') && (*format + 1))
			count += main_routine(fd, &format, &ap, count);
		else if (*format)
		{
			count += write(fd, format++, 1);
		}
	}
	va_end(ap);
	return (count);
}
