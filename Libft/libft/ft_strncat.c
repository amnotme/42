/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 09:35:08 by lhernand          #+#    #+#             */
/*   Updated: 2017/11/09 12:15:37 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_strcat() and ft_strncat() functions append a copy of the 
** null-terminated string s2 to the end of the null-terminated string s1, 
** then add a terminating `\0'.  The string s1 must have sufficient space to
** hold the result.
** 
** The ft_strncat() function appends not more than n characters from s2, 
** and then adds a terminating `\0'.
**
** The source and destination strings should not overlap, as the behavior 
** is undefined.
**
** The ft_strcat() and ft_strncat() functions return the pointer s1.
*/

char		*ft_strncat(char *s1, char const *s2, size_t n)
{
	size_t	l;
	size_t	i;
	char	*ptr;

	l = 0;
	i = 0;
	ptr = s1;
	while (s1[l] != '\0')
		l++;
	while ((s2[i] != '\0') && i < n)
	{
		s1[l] = s2[i];
		i++;
		l++;
	}
	s1[l] = '\0';
	s1 = ptr;
	return (s1);
}
