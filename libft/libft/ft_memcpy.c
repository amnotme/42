/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 05:39:23 by lhernand          #+#    #+#             */
/*   Updated: 2017/10/19 20:11:33 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *restrict su1;
	const char *restrict su2;

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