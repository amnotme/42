/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 21:12:49 by lhernand          #+#    #+#             */
/*   Updated: 2017/10/21 20:00:42 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
