/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 01:53:25 by brabo-hi          #+#    #+#             */
/*   Updated: 2017/12/23 23:10:09 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_helper.h"

char	*ft_concat(char *dest, char *str, int len)
{
	char	*out;

	len = len ? len : ft_strlen(str);
	if (!(out = ft_memalloc((len + (dest ? ft_strlen(dest) : 0) + 1))))
		exit(0);
	out = ft_strcat(out, dest);
	out = ft_strncat(out, str, len);
	free(dest);
	return (out);
}

int		ft_is_valid(char *str)
{
	int	i;

	i = -1;
	while (str && str[++i])
	{
		if (str[i] == '%' && ++i)
		{
			while (str && str[i] && !TYPE(str[i]))
			{
				if (!MOD(str[i]) && !FLAGS(str[i]) && !ft_isdigit(str[i]))
					return (0);
				i++;
			}
			if (!TYPE(str[i]))
				return (0);
		}
	}
	return (1);
}

int		ft_display(char *dest)
{
	int	i;
	int	len;

	len = ft_strlen(dest);
	i = 0;
	if (!dest)
		return (0);
	while (dest[i])
	{
		if (dest[i] == '^' && dest[i + 1] && dest[i + 1] == '@')
			len--;
		i++;
	}
	ft_putstr(dest);
	free(dest);
	return (len);
}

char	*ft_cut_str(char *out, int min)
{
	int		i;
	char	*dest;

	i = 0;
	if (ft_strlen(out) && (int)ft_strlen(out) <= min)
		return (out);
	if (!(dest = ft_memalloc(min + 1)))
		exit(0);
	while (min--)
		dest[i++] = out ? *out++ : (char)NULL;
	dest[i] = '\0';
	return (dest);
}

char	*ft_delete_last_zero(t_cs *cs, char *out)
{
	char	*dest;
	int		i;
	int		size;

	i = 0;
	size = cs->width ? ft_strlen(out) + 1 : ft_strlen(out);
	if (!(dest = ft_memalloc(size)))
		exit(0);
	size = cs->width ? size - 2 : size - 1;
	while (size--)
		dest[i++] = ' ';
	if (cs->width)
		dest[i++] = ' ';
	dest[i] = '\0';
	return (dest);
}
