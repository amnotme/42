/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 16:34:11 by lhernand          #+#    #+#             */
/*   Updated: 2017/11/09 01:31:05 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_memchr() function locates the first occurrence of c (converted to 
** an unsigned char) in string s.
**
** The ft_memchr() function returns a pointer to the byte located, or NULL 
** if no such byte exists within n bytes.
*/

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
