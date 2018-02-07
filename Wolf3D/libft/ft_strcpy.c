/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 09:41:25 by lhernand          #+#    #+#             */
/*   Updated: 2017/12/14 02:17:51 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_strcpy() functions copy the string src to dst (including the
** terminating `\0' character.)
**
** The source and destination strings should not overlap, as the behavior is
** undefined.
**
** The ft_strcpy() function returns dst.
*/

char		*ft_strcpy(char *dst, char const *src)
{
	int		i;
	char	*ptr;

	ptr = dst;
	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	dst = ptr;
	return (dst);
}
