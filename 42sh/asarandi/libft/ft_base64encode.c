/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base64encode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 20:14:04 by asarandi          #+#    #+#             */
/*   Updated: 2017/09/28 14:28:53 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef unsigned char	t_uc;
typedef char const		t_cc;
typedef size_t			t_st;

static char		*ft_b64algo(t_st k, t_st size, char *mem, t_uc *s)
{
	t_uc		c;
	t_uc		d;
	static char	*tab;
	t_st		i;

	tab = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	i = 0;
	while (i < size)
	{
		c = s[i] >> 2;
		mem[k++] = tab[c];
		c = s[i++] << 6;
		d = s[i] >> 4;
		mem[k++] = tab[(c >> 2) + d];
		c = s[i++] << 4;
		d = s[i] >> 6;
		mem[k++] = tab[(c >> 2) + d];
		c = ((s[i++]) << 2);
		mem[k++] = tab[c >> 2];
	}
	if (i - 2 == size)
		mem[k - 2] = '=';
	if (i - 1 >= size)
		mem[k - 1] = '=';
	return (mem);
}

char			*ft_base64encode(t_uc *o, t_st size)
{
	char		*mem;
	t_uc		*s;
	t_st		i;

	if ((s = ft_memalloc((size + 6) * sizeof(char))) == NULL)
		return (NULL);
	ft_memcpy(s, o, size);
	i = size;
	while (i < size + 6)
		s[i++] = 0;
	i = size;
	while (i % 3)
		i++;
	i /= 3;
	i *= 4;
	if ((mem = ft_memalloc((i + 1) * sizeof(char))) == NULL)
		return (NULL);
	return (ft_b64algo(0, size, mem, s));
}
