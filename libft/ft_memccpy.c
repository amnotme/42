/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 06:15:32 by lhernand          #+#    #+#             */
/*   Updated: 2017/09/28 16:33:22 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src, int c, size_t n)
{
	int i;
	
	i = 0;
	while (i < n)
	{
		(((unsigned char *)dst)[i]) = (((unsigned char *)src)[i]);
		if (((unsigned char *)src)[i] == (unsigned char)c)
			return (&((unsigned char *)dst)[i + 1]);		
		i++;
	}
	return (NULL);
}
