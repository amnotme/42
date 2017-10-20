/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 21:12:49 by lhernand          #+#    #+#             */
/*   Updated: 2017/09/28 04:39:35 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	int i;
	int j;
	int z;

	i = 0;
	j = 0;
	if (little[0] == '\0')
		return ((char *)&big[i]);
	while (big[i])
	{
		z = i;
		while ((big[z] == little[j]) && (little[j]) && (len != 0))
		{
			z++;
			j++;
			len--;
		}
		if	(!little[j])
			return ((char *)&big[i]);
		j = 0;
		i++;
	}
	return (0);
}



