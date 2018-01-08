/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 21:45:23 by lhernand          #+#    #+#             */
/*   Updated: 2017/11/09 16:16:14 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_wl() function counts the lengtha of any given string which is
** delimited by a delimiter passed in the parameters.
**
** Returns the l as the length.
*/

size_t				ft_wl(const char *s, char c)
{
	unsigned int	i;
	size_t			l;

	i = 0;
	l = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i++])
		l++;
	return (l);
}
