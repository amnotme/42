/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 16:42:50 by asarandi          #+#    #+#             */
/*   Updated: 2017/09/24 13:57:16 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	k;
	char	*s2;
	char	c;

	s2 = ft_strdup(s);
	if (s2 == NULL)
		return (s2);
	i = ft_strlen(s2);
	k = 0;
	while (k < i)
	{
		c = f((unsigned int)k, s2[k]);
		s2[k] = c;
		k++;
	}
	return (s2);
}
