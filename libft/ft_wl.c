/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 21:45:23 by lhernand          #+#    #+#             */
/*   Updated: 2017/10/21 01:35:42 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
