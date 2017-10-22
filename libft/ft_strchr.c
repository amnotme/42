/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 15:24:53 by lhernand          #+#    #+#             */
/*   Updated: 2017/10/21 19:57:43 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	ch;

	i = 0;
	ch = c;
	while (s[i] != ch)
	{
		if ((ft_strlen(s) == i) && (s[i] != ch))
			return (NULL);
		i++;
	}
	return ((char *)&s[i]);
}
