/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 09:37:22 by lhernand          #+#    #+#             */
/*   Updated: 2017/12/14 02:15:38 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_strncpy() function copies at most len characters from src into dst.
** If src is less than len characters long, the remainder of dst is filled
** with `\0' characters.  Otherwise, dst is not terminated.
**
** The source and destination strings should not overlap, as the behavior
** is undefined.
**
** The ft_strcpy() and ft_strncpy() functions return dst.
*/

char		*ft_strncpy(char *dst, char const *src, size_t len)
{
	size_t	i;
	char	*ptr;

	ptr = dst;
	i = 0;
	while ((i < len) && (src[i] != '\0'))
	{
		dst[i] = src[i];
		i++;
	}
	while (i < len)
	{
		dst[i] = '\0';
		i++;
	}
	dst = ptr;
	return (dst);
}
