/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 16:48:19 by lhernand          #+#    #+#             */
/*   Updated: 2017/12/14 02:21:19 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_memcmp() function compares byte string s1 against byte string s2.
** Both strings are assumed to be n bytes long.
**
** The ft_memcmp() function returns zero if the two strings are identical,
** otherwise returns the difference between the first two differing bytes
** (treated as unsigned char values, so that `\200' is greater than `\0',
** for example).  Zero-length strings are always identical.
*/

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (n > i)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
