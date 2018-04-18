/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uriencode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 15:46:21 by asarandi          #+#    #+#             */
/*   Updated: 2017/09/28 13:32:39 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ue_unreserved(int c)
{
	if (ft_isalnum(c))
		return (1);
	if ((c == '-') || (c == '_'))
		return (1);
	if ((c == '.') || (c == '~'))
		return (1);
	return (0);
}

static int	ft_ue_length(char *s)
{
	int	i;
	int r;

	i = 0;
	r = 0;
	while (s[i])
	{
		if (ft_ue_unreserved(s[i]))
			r++;
		i++;
	}
	return (((ft_strlen(s) - r) * 3) + r);
}

char		*ft_uriencode(char *s)
{
	const char	*hex = "0123456789ABCDEF";
	char		*mem;
	int			i;
	int			k;

	mem = malloc((ft_ue_length(s) + 1) * sizeof(char));
	if (!mem)
		return (NULL);
	i = 0;
	k = 0;
	while (s[i])
	{
		if (ft_ue_unreserved(s[i]))
			mem[k++] = s[i];
		else
		{
			mem[k++] = '%';
			mem[k++] = hex[s[i] / 16];
			mem[k++] = hex[s[i] % 16];
		}
		i++;
	}
	mem[k] = 0;
	return (mem);
}
