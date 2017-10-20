/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 09:37:22 by lhernand          #+#    #+#             */
/*   Updated: 2017/09/25 09:39:51 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char 		*ft_strncpy(char *dst, char const *src, size_t len)
{
	int		i;
	char	*ptr;

	ptr = dst;	
	i = 0;
	while ((i < len) && (src[i] != '\0'))
	{
		dst[i] = src[i];
		i++;
	}
	while (i < len)
	{
		dst[i] = '\0';
		i++;
	}	
	dst = ptr;
	return (dst);
}
