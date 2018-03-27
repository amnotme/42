/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 15:55:25 by lhernand          #+#    #+#             */
/*   Updated: 2017/12/14 02:12:57 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_strchr() function locates the first occurrence of c (converted to a
** char) in the string pointed to by s.  The terminating null character is
** considered to be part of the string; therefore if c is `\0', the functions
** locate the terminating `\0'.
**
** The ft_strrchr() function is identical to ft_strchr(), except it locates
** the last occurrence of c.
*/

char		*ft_strrchr(char const *s, int c)
{
	int		i;
	char	ch;

	ch = c;
	i = ft_strlen(s);
	while (s[i] != ch)
	{
		if ((i == 0) && (s[i] != ch))
			return (NULL);
		i--;
	}
	return ((char *)&s[i]);
}
