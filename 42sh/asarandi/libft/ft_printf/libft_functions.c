/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 01:21:20 by asarandi          #+#    #+#             */
/*   Updated: 2017/11/08 19:55:32 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strtoupper(char *s)
{
	size_t	i;
	size_t	k;

	i = ft_strlen(s);
	k = 0;
	while (k < i)
	{
		if ((s[k] >= 'a') && (s[k] <= 'z'))
			s[k] = s[k] - 0x20;
		k++;
	}
	return (s);
}

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

void	*ft_memalloc(size_t size)
{
	unsigned char	*p;
	size_t			i;

	if ((p = malloc(size)) == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		p[i] = 0;
		i++;
	}
	return (p);
}

char	*ft_strdup(const char *s1)
{
	char	*mem;

	mem = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (mem == NULL)
		return (NULL);
	return (ft_strcpy(mem, s1));
}
