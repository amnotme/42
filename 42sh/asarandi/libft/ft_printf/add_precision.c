/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:45:22 by asarandi          #+#    #+#             */
/*   Updated: 2017/11/11 18:47:52 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	add_wide_string_precision(t_placeholder *ph)
{
	int	i;

	i = (*ph).precision;
	if (((*ph).have_precision) && (i >= 0))
	{
		while ((i >= 0) && (((*ph).output[i] >> 6) == 2))
			i--;
		if ((i >= 0) && (((*ph).output[i] >> 6) != 2))
			(*ph).output[i] = 0;
		(*ph).char_count = ft_strlen((char *)(*ph).output);
	}
}

void	add_string_precision(t_placeholder *ph)
{
	int	i;

	if (((*ph).type == 's') && ((*ph).length <= 32))
	{
		i = (*ph).precision;
		if (((*ph).have_precision) && (i >= 0))
		{
			(*ph).output[i] = 0;
			(*ph).char_count = ft_strlen((char *)(*ph).output);
		}
	}
	else if (((*ph).type == 's') && ((*ph).length > 32))
		add_wide_string_precision(ph);
	else if ((*ph).type == 'S')
		add_wide_string_precision(ph);
}

void	add_precision(t_placeholder *ph)
{
	if ((*ph).have_precision)
	{
		if (is_numeric((*ph).type))
		{
			while ((*ph).precision > (*ph).char_count)
				string_prefix(ph, "0");
			(*ph).flags &= ~(1 << 1);
			if (((*ph).precision == 0) && ((*ph).n == 0))
			{
				(*ph).output[0] = 0;
				(*ph).char_count = 0;
			}
		}
		else if (((*ph).type == 'f') || ((*ph).type == 'F'))
		{
			while ((*ph).char_count < (*ph).precision)
				string_suffix(ph, "0");
			(*ph).char_count = (*ph).precision;
			(*ph).output[(*ph).precision] = 0;
		}
		else
			add_string_precision(ph);
	}
}
