/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 09:37:45 by lhernand          #+#    #+#             */
/*   Updated: 2017/10/21 19:59:45 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
