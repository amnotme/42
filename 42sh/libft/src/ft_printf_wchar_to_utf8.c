/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_to_utf8.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 18:34:04 by asarandi          #+#    #+#             */
/*   Updated: 2017/11/10 15:59:11 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		wchar_to_utf8(unsigned int wchar, unsigned char *output)
{
	if ((wchar > 0x7F) && (wchar <= 0x7FF))
	{
		output[0] = ((wchar >> 6) & 0x1F) + 0xC0;
		output[1] = (wchar & 0x3F) + 0x80;
		return (2);
	}
	else if ((wchar > 0x7FF) && (wchar <= 0xFFFF))
	{
		output[0] = ((wchar >> 12) & 0xF) + 0xE0;
		output[1] = ((wchar >> 6) & 0x3F) + 0x80;
		output[2] = (wchar & 0x3F) + 0x80;
		return (3);
	}
	else if ((wchar > 0xFFFF) && (wchar <= 0x1FFFFF))
	{
		output[0] = ((wchar >> 18) & 0x7) + 0xF0;
		output[1] = ((wchar >> 12) & 0x3F) + 0x80;
		output[2] = ((wchar >> 6) & 0x3F) + 0x80;
		output[3] = (wchar & 0x3F) + 0x80;
		return (4);
	}
	output[0] = wchar & 0x7F;
	return (1);
}
