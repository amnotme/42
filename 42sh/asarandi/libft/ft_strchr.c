/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:36:54 by asarandi          #+#    #+#             */
/*   Updated: 2017/09/20 18:01:12 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int n;
	int i;

	n = ft_strlen(s);
	i = 0;
	while (i <= n)
	{
		if (s[i] == c)
			return (char *)&s[i];
		i++;
	}
	return (NULL);
}
