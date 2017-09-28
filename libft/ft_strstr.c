/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 19:08:21 by lhernand          #+#    #+#             */
/*   Updated: 2017/09/28 02:17:34 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
