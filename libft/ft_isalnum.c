/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 09:40:11 by lhernand          #+#    #+#             */
/*   Updated: 2017/11/09 13:26:35 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_isalnum() function tests for any character for which ft_isalpha() or
** ft_isdigit() is true.  The value of the argument must be representable as an
** unsigned char or the value of EOF.
**
** The ft_isalnum() function returns zero if the character tests false and
** returns non-zero if the character tests true.
*/

int		ft_isalnum(int c)
{
	if (ft_isdigit(c) || ft_isalpha(c))
		return (1);
	else
		return (0);
}
