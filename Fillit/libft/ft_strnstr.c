/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regien <gmalpart@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 15:00:24 by regien            #+#    #+#             */
/*   Updated: 2017/10/20 01:25:05 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *litle, size_t len)
{
	size_t	i;
	size_t	d;

	i = 0;
	d = 0;
	if (!litle[0])
		return ((char *)big);
	while (big[i] && i < len)
	{
		while (big[i + d] == litle[d] && litle[d] && (i + d) < len)
			d++;
		if (!litle[d])
			return ((char *)(big + i));
		d = 0;
		i++;
	}
	return (NULL);
}
