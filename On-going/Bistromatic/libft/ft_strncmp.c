/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 09:37:45 by lhernand          #+#    #+#             */
/*   Updated: 2017/12/14 02:20:43 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_strcmp() and ft_strncmp() functions lexicographically compare the
** null-terminated strings s1 and s2.
**
** The ft_strncmp() function compares not more than n characters.  Because
** ft_strncmp() is designed for comparing strings rather than binary data,
** characters that appear after a `\0' character are not compared.
**
** The ft_strcmp() and ft_strncmp() functions return an integer greater than,
** equal to, or less than 0, according as the string s1 is greater than,
** equal to, or less than the string s2.  The comparison is done using
** unsigned characters, so that `\200' is greater than `\0'.
*/

int					ft_strncmp(char const *s1, char const *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while ((str1[i] != '\0') && (str2[i] != '\0') && (i < n))
	{
		if ((str1[i] != str2[i]) || (i + 1 == n))
			return (str1[i] - str2[i]);
		i++;
	}
	return (str1[i] - str2[i]);
}
