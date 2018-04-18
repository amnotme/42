/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 10:03:55 by asarandi          #+#    #+#             */
/*   Updated: 2017/09/22 09:36:13 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	d;
	size_t	i;

	d = ft_strlen(dest);
	i = 0;
	while ((i < n) && src[i] != 0)
	{
		dest[d + i] = src[i];
		i++;
	}
	dest[d + i] = 0;
	return (dest);
}
