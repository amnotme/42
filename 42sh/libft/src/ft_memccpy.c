/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 09:09:18 by asarandi          #+#    #+#             */
/*   Updated: 2017/09/21 09:14:58 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;
	unsigned char		b;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	b = c;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		if (d[i] == b)
			return (void *)(&d[++i]);
		i++;
	}
	return (NULL);
}
