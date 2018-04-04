/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:50:09 by asarandi          #+#    #+#             */
/*   Updated: 2017/11/10 16:01:53 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	calculate_reserve(int *reserve, t_placeholder *ph)
{
	*reserve = 0;
	if (((*ph).type == 'p') && ((*ph).flags & FLAG_ZERO))
		*reserve = 2;
	if ((is_signed((*ph).type)) && ((*ph).flags & FLAG_ZERO))
	{
		if ((*ph).flags & FLAG_PLUS)
			*reserve = 1;
		else if ((*ph).sign == '-')
			*reserve = 1;
		if ((*ph).flags & FLAG_SPACE)
			*reserve += 1;
	}
	if (((*ph).flags & FLAG_HASHTAG) && ((*ph).flags & FLAG_ZERO))
	{
		if ((*ph).type == 'o')
			*reserve = 1;
		if (((*ph).type == 'x') || ((*ph).type == 'X'))
			*reserve = 2;
	}
}

void	add_width(t_placeholder *ph)
{
	int	reserve;

	calculate_reserve(&reserve, ph);
	if ((*ph).have_width)
	{
		if ((*ph).flags & FLAG_MINUS)
		{
			while ((*ph).width > (*ph).char_count + reserve)
				binary_suffix(ph, " ");
			(*ph).flags &= ~(1 << 1);
		}
		else
		{
			while ((*ph).width > (*ph).char_count + reserve)
			{
				if ((*ph).flags & FLAG_ZERO)
					string_prefix(ph, "0");
				else
					string_prefix(ph, " ");
			}
		}
	}
}

void	flag_space(t_placeholder *ph)
{
	if ((is_signed((*ph).type)) && ((*ph).sign == '+'))
	{
		if ((*ph).output[0] != ' ')
			string_prefix(ph, " ");
	}
}

void	flag_plus(t_placeholder *ph)
{
	(*ph).flags &= ~(1 << 3);
	if ((*ph).sign == '+')
		string_prefix(ph, "+");
	else
		string_prefix(ph, "-");
}
