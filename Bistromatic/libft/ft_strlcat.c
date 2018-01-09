/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 17:05:49 by lhernand          #+#    #+#             */
/*   Updated: 2017/12/14 02:29:36 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_strlcat() function appends the NUL-terminated string src to the end
** dst. It will append at most size - ft_strlen(dst) - 1 bytes, NUL-terminating
** the result.
**
** The source and destination strings should not overlap, as the behavior is
** undefined.
**
** The ft_strlcat() function returns the total length of the string it tried
** to create.  For ft_strlcat() that means the initial length of dst plus the
** length of src.
**
** Note however, that if ft_strlcat() traverses size characters without
** finding a NUL, the length of the string is considered to be size and the
** destination string will not be NUL-terminated (since there was no space
** for the NUL).  This keeps ft_strlcat() from running off the end of a string
** In practice this should not happen (as it means that either size is
** incorrect or that dst is not a proper ``C'' string). The check exists to
** prevent potential security problems in incorrect code.
*/

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	l;

	l = 0;
	while ((dst[l] != '\0') && (l < size))
		l++;
	i = l;
	while ((src[l - i]) && (l + 1 < size))
	{
		dst[l] = src[l - i];
		l++;
	}
	if (i < size)
		dst[l] = '\0';
	return (i + ft_strlen(src));
}
