/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regien <gmalpart@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 15:55:39 by regien            #+#    #+#             */
/*   Updated: 2017/10/21 06:53:50 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*contdst;
	unsigned char	*contsrc;

	i = 0;
	contdst = (unsigned char *)dst;
	contsrc = (unsigned char *)src;
	if (contsrc < contdst)
	{
		while (n-- > 0)
			contdst[n] = contsrc[n];
	}
	else
	{
		while (i < n)
		{
			contdst[i] = contsrc[i];
			i++;
		}
	}
	return (contdst);
}
