/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 09:43:11 by lhernand          #+#    #+#             */
/*   Updated: 2017/12/14 02:17:30 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_toupper() function converts a lower-case letter to the corresponding
** upper-case letter.  The argument must be representable as an unsigned char
** or the value of EOF.
**
** If the argument is a lower-case letter, the ft_toupper() function returns
** the corresponding upper-case letter if there is one; otherwise, the
** argument is returned unchanged.
*/

int		ft_toupper(int c)
{
	if ((c >= 'a') && (c <= 'z'))
		return (c - 32);
	else
		return (c);
}
