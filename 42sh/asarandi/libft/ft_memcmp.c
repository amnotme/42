/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 11:12:33 by asarandi          #+#    #+#             */
/*   Updated: 2017/09/22 11:17:04 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*u1;
	const unsigned char	*u2;
	size_t				i;

	u1 = s1;
	u2 = s2;
	i = 0;
	if ((!u1[i]) && (!u2[i]))
		return (0);
	while (i < n)
	{
		if (u1[i] != u2[i])
			break ;
		i++;
	}
	if (i == n)
		return (0);
	return (u1[i] - u2[i]);
}
