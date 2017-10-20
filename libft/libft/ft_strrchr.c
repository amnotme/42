/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 15:55:25 by lhernand          #+#    #+#             */
/*   Updated: 2017/09/25 16:11:38 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(char const *s, int c)
{
	int i;
	char ch;

	ch = c;
	i = ft_strlen(s);

	while (s[i] != ch)
	{
		if ((i == 0) && (s[i] != ch))
			return (NULL);
		i--;
	}
	return ((char *)&s[i]);
}
