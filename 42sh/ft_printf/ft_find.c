/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 22:57:54 by brabo-hi          #+#    #+#             */
/*   Updated: 2017/12/21 23:01:58 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_find.h"

int		ft_find_max(t_cs *cs, int min, int prefix)
{
	int	max;
	int	precision;
	int	width;

	precision = cs->precision + prefix;
	width = cs->width;
	max = 0;
	if (precision >= width && precision >= min)
		max = precision;
	if (precision >= width && precision <= min)
		max = min;
	if (precision <= width && precision >= min)
		max = width;
	if (precision < width && precision < min && width >= min)
		max = width;
	if (precision < width && precision < min && width <= min)
		max = min;
	return (max);
}

int		ft_find_min(t_cs *cs, int len, int prefix)
{
	int	precision;

	len += prefix;
	precision = cs->precision + prefix;
	return (precision > len ? precision : len);
}

int		ft_find_zero(t_cs *cs, char *dest, char prefix, int min)
{
	int	size_prefix;

	size_prefix = prefix ? 1 : 0;
	if (cs->precision)
		return (cs->precision + prefix > min ? cs->precision : min);
	return (ft_strlen(dest));
}
