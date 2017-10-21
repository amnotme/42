/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 16:34:11 by lhernand          #+#    #+#             */
/*   Updated: 2017/10/21 02:04:00 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *s1;
	unsigned char		ch;

	s1 = s;
	ch = c;
	while (n > 0)
	{
		if (*s1 == ch)
			return ((unsigned char *)s1);
		s1++;
		n--;
	}
	return (NULL);
}
