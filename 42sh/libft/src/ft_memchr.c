/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 11:01:54 by asarandi          #+#    #+#             */
/*   Updated: 2017/09/22 11:19:05 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*m;

	i = 0;
	m = s;
	while (i < n)
	{
		if (m[i] == (unsigned char)c)
			return (void *)(&m[i]);
		i++;
	}
	return (NULL);
}
