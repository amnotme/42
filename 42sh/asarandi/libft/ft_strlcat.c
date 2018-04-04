/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 12:04:46 by asarandi          #+#    #+#             */
/*   Updated: 2017/09/23 13:48:46 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		dl;
	size_t		sl;
	size_t		i;

	d = dst;
	s = src;
	dl = ft_strlen(d);
	sl = ft_strlen(s);
	if (dl > size)
		return (size + sl);
	i = 0;
	while ((dl + i + 1 < size) && (s[i] != 0))
	{
		d[dl + i] = s[i];
		i++;
	}
	if (dl + i < size)
		d[dl + i] = 0;
	return (dl + sl);
}
