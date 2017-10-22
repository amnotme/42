/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 09:35:08 by lhernand          #+#    #+#             */
/*   Updated: 2017/10/21 19:59:12 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *s1, char const *s2, size_t n)
{
	size_t	l;
	size_t	i;
	char	*ptr;

	l = 0;
	i = 0;
	ptr = s1;
	while (s1[l] != '\0')
		l++;
	while ((s2[i] != '\0') && i < n)
	{
		s1[l] = s2[i];
		i++;
		l++;
	}
	s1[l] = '\0';
	s1 = ptr;
	return (s1);
}
