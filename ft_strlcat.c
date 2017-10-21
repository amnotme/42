/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 17:05:49 by lhernand          #+#    #+#             */
/*   Updated: 2017/10/19 20:03:42 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int i;
	int l;

	l = 0;
	while ((dst[l] != '\0') && (l < size))
		l++;
	i = l;
	while ((src[l - i]) && (l + 1 < size))
	{
		dst[l] = src[l - i];
		l++;
	}
	if (i < size)
		dst[l] = '\0';
	return (i + ft_strlen(src));
}
