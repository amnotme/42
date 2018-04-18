/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso8601.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:06:01 by asarandi          #+#    #+#             */
/*   Updated: 2018/03/31 04:59:57 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** function will print time to file descriptor 1, STDOUT
*/

void	iso_time(uintmax_t t)
{
	int			leaps;
	int			is_leap;
	int			day;
	static int	months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int			mo;

	leaps = 0;
	is_leap = 0;
	if ((t / 31536000) >= 2)
		leaps = ((t / 31536000) + 2) / 4;
	if (((t / 31536000) + 2) % 4 == 0)
		is_leap = 1;
	day = ((t / 86400) - (leaps - is_leap)) % 365;
	day += 1;
	mo = 0;
	months[1] = 28;
	if (is_leap)
		months[1] = 29;
	while (day > months[mo])
		day -= months[mo++];
	leaps = (leaps - is_leap) * 86400;
	ft_printf(1, "%d-%02d-%02d", ((t - leaps) / 31536000) + 1970, ++mo, day);
	ft_printf(1, "T%02d:%02d:%02d+00:00", t / 3600 % 24, t / 60 % 60, t % 60);
}
