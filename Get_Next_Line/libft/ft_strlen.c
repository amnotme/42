/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 09:42:54 by lhernand          #+#    #+#             */
/*   Updated: 2017/11/09 01:37:39 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

/*
** The ft_strlen() function computes the length of the string s. ft_strnlen() 
** function attempts to compute the length of s, but never scans beyond the 
** first maxlen bytes of s.
**
** The ft_strlen() function returns the number of characters that precede 
** the terminating NUL character.  The ft_strnlen() function returns either
** the same result as ft_strlen() or maxlen, whichever is smaller. 
*/

size_t			ft_strlen(char const *s)
{
	size_t		i;
	char const	*ptr;

	i = 0;
	ptr = s;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
