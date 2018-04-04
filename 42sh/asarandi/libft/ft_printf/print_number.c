/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 01:26:48 by asarandi          #+#    #+#             */
/*   Updated: 2017/11/11 19:14:47 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	trim_bits(t_placeholder *ph)
{
	uintmax_t	result;

	result = (*ph).n;
	if ((*ph).length == 8)
		result &= UINT8_MAX;
	else if ((*ph).length == 16)
		result &= UINT16_MAX;
	else if ((*ph).length == 32)
		result &= UINT32_MAX;
	else if ((*ph).length == 64)
		result &= UINT64_MAX;
	(*ph).n = result;
	return ;
}

void	check_negative(t_placeholder *ph)
{
	int			negative;
	uintmax_t	n;

	if (is_signed((*ph).type) == 0)
		return ;
	n = (*ph).n;
	negative = 0;
	if (((*ph).length == 8) && (n > INT8_MAX))
		negative = 1;
	if (((*ph).length == 16) && (n > INT16_MAX))
		negative = 1;
	if (((*ph).length == 32) && (n > INT32_MAX))
		negative = 1;
	if (((*ph).length == 64) && (n > INT64_MAX))
		negative = 1;
	(*ph).n = negative ? -n : n;
	if (negative)
		(*ph).sign = '-';
	else
		(*ph).sign = '+';
	trim_bits(ph);
}

void	make_numeric_output(t_placeholder *ph)
{
	uintmax_t	n;
	int			base;
	int			i;
	char		buffer[128];
	const char	*hex = "0123456789abcdef";

	base = get_base((*ph).type);
	trim_bits(ph);
	check_negative(ph);
	i = 127;
	buffer[i--] = 0;
	n = (*ph).n;
	if (n == 0)
		buffer[i--] = '0';
	while (n)
	{
		buffer[i--] = hex[n % base];
		n /= base;
	}
	i++;
	(*ph).output = ft_memalloc(ft_strlen(&buffer[i]) + 1);
	if ((*ph).output != NULL)
		ft_strcpy((char *)(*ph).output, &buffer[i]);
	return ;
}

char	*float_itoa(uintmax_t n)
{
	int			i;
	char		buffer[32];

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
	return (ft_strdup(&buffer[i]));
}
