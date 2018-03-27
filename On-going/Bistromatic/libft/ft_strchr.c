/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 15:24:53 by lhernand          #+#    #+#             */
/*   Updated: 2017/12/14 02:23:48 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_strchr() function locates the first occurrence of c (converted to
** a char) in the string pointed to by s.  The terminating null character is
** considered to be part of the string; therefore if c is `\0', the function
** locates the terminating `\0'.
**
** ft_strchr() returns a pointer to the located character, or NULL if the
** character does not appear in the string.
*/

char		*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	ch;

	i = 0;
	ch = c;
	while (s[i] != ch)
	{
		if ((ft_strlen(s) == i) && (s[i] != ch))
			return (NULL);
		i++;
	}
	return ((char *)&s[i]);
}
