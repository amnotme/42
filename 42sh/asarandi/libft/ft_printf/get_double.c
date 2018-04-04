/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_double.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:01:00 by asarandi          #+#    #+#             */
/*   Updated: 2017/11/12 17:37:11 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*float_str_append(char *str, uintmax_t n)
{
	int		i;
	int		k;
	char	buffer[32];
	char	*new_str;

	i = 31;
	buffer[i--] = 0;
	if (n == 0)
		buffer[i--] = '0';
	while (n)
	{
		buffer[i--] = (n % 10) + '0';
		n /= 10;
	}
	i++;
	if (!str)
		return (ft_strdup(&buffer[i]));
	k = ft_strlen(&buffer[i]) + ft_strlen(str);
	new_str = ft_memalloc(k + 1);
	ft_strcpy(new_str, str);
	free(str);
	ft_strcpy(&new_str[ft_strlen(new_str)], &buffer[i]);
	return (new_str);
}

int		double_check_nan(double *d, t_placeholder *ph)
{
	if (*d < (double)0)
	{
		(*ph).sign = '-';
		*d = (-*d);
	}
	else
		(*ph).sign = '+';
	if (*d != *d)
	{
		(*ph).float_suffix = ft_strdup("nan");
		(*ph).float_prefix = ft_memalloc(1);
		(*ph).char_count = 3;
		return (1);
	}
	if ((*d == (double)1 / (double)0) || (*d == (double)-1 / (double)0))
	{
		(*ph).float_suffix = ft_strdup("inf");
		(*ph).float_prefix = ft_memalloc(1);
		(*ph).char_count = 3;
		return (1);
	}
	return (0);
}

void	get_double(va_list *ap, t_placeholder *ph)
{
	long double	x;
	long double	tail;
	double		d;
	int			decimals;

	d = va_arg(*ap, double);
	if (double_check_nan(&d, ph))
		return ;
	(*ph).float_prefix = float_str_append((*ph).float_prefix, (uintmax_t)d);
	tail = d - (long double)(uintmax_t)d;
	decimals = (*ph).precision + 1;
	while (decimals--)
	{
		tail *= (long double)10.0;
		x = (uintmax_t)(long double)tail;
		(*ph).float_suffix = float_str_append((*ph).float_suffix,
				(uintmax_t)(long double)x);
		tail -= (long double)x;
	}
	decimals = float_round_suffix((*ph).float_suffix, 0);
	(*ph).float_prefix = float_round_prefix((*ph).float_prefix, decimals);
}

void	format_double(t_placeholder *ph)
{
	(*ph).output = (unsigned char *)(*ph).float_suffix;
	if (((*ph).output[0] != 'n') && ((*ph).output[0] != 'i'))
	{
		if ((*ph).have_precision == 0)
		{
			if (ft_strlen((char *)(*ph).output) > 6)
				(*ph).output[6] = 0;
			while (ft_strlen((char *)(*ph).output) < 6)
				string_suffix(ph, "0");
		}
		(*ph).char_count = ft_strlen((char *)(*ph).output);
		add_precision(ph);
		if (((*ph).have_precision) && ((*ph).precision > 0))
			string_prefix(ph, ".");
		string_prefix(ph, (*ph).float_prefix);
	}
	free((*ph).float_prefix);
	float_cosmetics(ph);
	add_width(ph);
}
