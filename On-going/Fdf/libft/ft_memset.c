/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 03:16:46 by lhernand          #+#    #+#             */
/*   Updated: 2017/12/14 02:21:49 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The memset() function writes len bytes of value c (converted to an
** unsigned char) to the string b.
*/

#include "libft.h"

void		*ft_memset(void *b, int c, size_t len)
{
	unsigned char uc;
	unsigned char *su;

	uc = c;
	su = b;
	while (0 < len)
	{
		*su = uc;
		su++;
		len--;
	}
	return ((unsigned char *)b);
}
