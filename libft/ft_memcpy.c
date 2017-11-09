/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 05:39:23 by lhernand          #+#    #+#             */
/*   Updated: 2017/11/09 01:20:52 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_memcpy() function copies n bytes from memory area src to memory area dst.
** If dst and src overlap, behavior is undefined.  Applications in which dst 
** and src might overlap should use ft_memmove instead.
*/

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*su1;
	const char	*su2;

	su1 = dst;
	su2 = src;
	while (0 < n)
	{
		*su1 = *su2;
		su1++;
		su2++;
		n--;
	}
	return (dst);
}
