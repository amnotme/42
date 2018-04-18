/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 03:50:34 by asarandi          #+#    #+#             */
/*   Updated: 2017/11/11 19:40:31 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	is_numeric(char type)
{
	if ((type == 'p') || (type == 'd') || (type == 'D') || (type == 'i'))
		return (1);
	else if ((type == 'o') || (type == 'O') || (type == 'u'))
		return (1);
	else if ((type == 'U') || (type == 'x') || (type == 'X'))
		return (1);
	else if (type == 'b')
		return (1);
	else
		return (0);
}

int	get_default_length(char type)
{
	if ((type == 'd') || (type == 'o') || (type == 'u') || (type == 'b'))
		return (sizeof(int) * CHAR_BIT);
	else if ((type == 'i') || (type == 'x') || (type == 'X'))
		return (sizeof(int) * CHAR_BIT);
	else if ((type == 'D') || (type == 'O') || (type == 'U'))
		return (sizeof(long) * CHAR_BIT);
	else if (type == 'p')
		return (sizeof(ptrdiff_t) * CHAR_BIT);
	else
		return (0);
}

int	is_signed(char type)
{
	if ((type == 'd') || (type == 'D') || (type == 'i'))
		return (1);
	else
		return (0);
}

int	is_decimal(char type)
{
	if ((type == 'd') || (type == 'D') || (type == 'i'))
		return (1);
	else if ((type == 'u') || (type == 'U'))
		return (1);
	else
		return (0);
}

int	get_base(char type)
{
	if ((type == 'd') || (type == 'D') || (type == 'i'))
		return (10);
	else if ((type == 'u') || (type == 'U'))
		return (10);
	else if ((type == 'o') || (type == 'O'))
		return (8);
	else if ((type == 'x') || (type == 'X') || (type == 'p'))
		return (16);
	else if (type == 'b')
		return (2);
	else
		return (0);
}
