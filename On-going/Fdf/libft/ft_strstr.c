/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 19:08:21 by lhernand          #+#    #+#             */
/*   Updated: 2017/11/09 12:41:53 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_strstr() function locates the first occurrence of the null-terminated
** string little in the null-terminated string big.
**
** If little is an empty string, big is returned; if little occurs nowhere in
** big, NULL is returned; otherwise a pointer to the first character of the
** first occurrence of little is returned.
*/

char		*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;
	int z;

	z = 0;
	i = 0;
	j = 0;
	if (!little[0])
		return ((char *)&big[i]);
	while (big[i])
	{
		z = i;
		while ((big[z] == little[j]) && (little[j]))
		{
			z++;
			j++;
		}
		if (!little[j])
			return ((char *)&big[i]);
		j = 0;
		i++;
	}
	return (0);
}
