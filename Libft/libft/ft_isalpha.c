/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 09:42:22 by lhernand          #+#    #+#             */
/*   Updated: 2017/11/09 13:00:18 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_isalpha() function tests for any character for which ft_isupper() or
** ft_islower() is true.  The value of the argument must be representable as
** an unsigned char or the value of EOF.
**
** The ft_isalpha() function returns zero if the character tests false and
** returns non-zero if the character tests true.
*/

int			ft_isalpha(int c)
{
	if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')))
		return (1);
	else
		return (0);
}
