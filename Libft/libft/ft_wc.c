/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 21:41:47 by lhernand          #+#    #+#             */
/*   Updated: 2017/11/09 16:13:41 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_wc() is a word count function that counts the number of words in a 
** given string.
**
** Returns the number of word characters.
**
** This is a helper function to ft_strplit().
*/

size_t		ft_wc(const char *s, char c)
{
	unsigned int	i;
	size_t			w;

	i = 0;
	w = 0;
	while (s[i])
	{
		if (s[i] != c)
			w++;
		while (s[i] != c && s[i + 1])
			i++;
		i++;
	}
	return (w);
}
