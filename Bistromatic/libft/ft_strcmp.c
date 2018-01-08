/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 09:39:08 by lhernand          #+#    #+#             */
/*   Updated: 2017/11/09 12:50:56 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strcmp()function lexicographically compares the null-terminated
** strings s1 and s2.
**
** The ft_strcmp() function returns an integer greater than, equal to, or less
** than 0, according as the string s1 is greater than, equal to, or less than
** the string s2.  The comparison is done using unsigned characters, so that
** `\200' is greater than `\0'.
*/

int				ft_strcmp(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while ((str1[i] != '\0') && (str2[i] != '\0'))
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (str1[i] - str2[i]);
}
