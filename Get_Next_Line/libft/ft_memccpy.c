/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 06:15:32 by lhernand          #+#    #+#             */
/*   Updated: 2017/11/09 01:25:30 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_memccpy() function copies bytes from string src to string dst.  
** If the character c (as converted to an unsigned char) occurs in the 
** string src, the copy stops and a pointer to the byte after the copy of c 
** in the string dst is returned.  Otherwise, n bytes are copied, and a NULL 
** pointer is returned.
**
** The source and destination strings should not overlap, as the behavior 
** is undefined.
*/

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		(((unsigned char *)dst)[i]) = (((unsigned char *)src)[i]);
		if (((unsigned char *)src)[i] == (unsigned char)c)
			return (&((unsigned char *)dst)[i + 1]);
		i++;
	}
	return (NULL);
}
