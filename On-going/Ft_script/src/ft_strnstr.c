/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 21:12:49 by lhernand          #+#    #+#             */
/*   Updated: 2017/11/09 12:45:11 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_strnstr() function locates the first occurrence of the null-terminated
** string little in the string big, where not more than len characters are
** searched.  Characters that appear after a `\0' character are not searched.
**
** If little is an empty string, big is returned; if little occurs nowhere in
** big, NULL is returned; otherwise a pointer to the first character of the
** first occurrence of little is returned.
*/

char		*ft_strnstr(const char *big, const char *little, size_t l)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (big[i] && (i < l))
	{
		while ((big[i + j] == little[j]) && (little[j]) && ((i + j) < l))
			j++;
		if (!little[j])
			return ((char *)&big[i]);
		j = 0;
		i++;
	}
	if (!little[0])
		return ((char *)&big[i]);
	return (NULL);
}
