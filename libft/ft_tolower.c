/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 09:41:50 by lhernand          #+#    #+#             */
/*   Updated: 2017/11/09 13:34:19 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_tolower() function converts an upper-case letter to the corresponding
** lower-case letter.  The argument must be representable as an unsigned char
** or the value of EOF.
**
** If the argument is an upper-case letter, the ft_tolower() function returns
** the corresponding lower-case letter if there is one; otherwise, the argument
** is returned unchanged.
*/

int		ft_tolower(int c)
{
	if ((c >= 'A') && (c <= 'Z'))
		return (c + 32);
	else
		return (c);
}
