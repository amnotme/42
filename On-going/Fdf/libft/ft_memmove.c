/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 16:33:56 by lhernand          #+#    #+#             */
/*   Updated: 2017/12/14 02:28:32 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_memmove() function copies len bytes from string src to string dst.
** The two strings may overlap; the copy is always done in a
** non-destructive manner.
*/

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if ((s < d) && (d < s + len))
	{
		d = d + len - 1;
		s = s + len - 1;
		while (len > 0)
		{
			*d-- = *s--;
			len--;
		}
	}
	else
	{
		while (len > 0)
		{
			*d++ = *s++;
			len--;
		}
	}
	return (dst);
}
