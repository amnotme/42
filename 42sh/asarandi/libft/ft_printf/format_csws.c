/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_csws.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:53:56 by asarandi          #+#    #+#             */
/*   Updated: 2017/11/12 00:50:53 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	format_string(t_placeholder *ph)
{
	add_precision(ph);
	add_width(ph);
}

void	format_wide_string(t_placeholder *ph)
{
	add_precision(ph);
	add_width(ph);
}

void	format_char(t_placeholder *ph)
{
	add_precision(ph);
	add_width(ph);
}

void	format_wide_char(t_placeholder *ph)
{
	add_precision(ph);
	add_width(ph);
}
