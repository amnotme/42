/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 23:12:48 by brabo-hi          #+#    #+#             */
/*   Updated: 2017/12/23 23:14:12 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_add.h"

char	*ft_add_zero(char *dest, int min, int prefix)
{
	int	i;

	i = 0;
	min = prefix ? min - prefix : min;
	if (*dest != ' ')
		return (dest);
	while (dest[i] == ' ' && (i < (int)ft_strlen(dest) - min))
		i++;
	while (dest[i] == ' ')
		dest[i++] = '0';
	return (dest);
}

char	*ft_add_prefix(char *out, char prefix1, char prefix2)
{
	int		i;
	char	*del;

	i = 0;
	del = out;
	if (*out != '0' && *out != ' ')
		return (ft_add_prefix_help(out, prefix1, prefix2));
	if (out && *out == '0' && ft_strlen(out) > 1)
	{
		*out = prefix1;
		return (out);
	}
	while ((!prefix2 && out && out[i] == ' ' && out[i + 1] == ' ')
			|| (prefix2 && out && out[i] == ' '
				&& out[i + 1] == ' ' && out[i + 2] == ' '))
		i++;
	out[i++] = prefix1;
	out[i] = prefix2 ? prefix2 : out[i];
	return (out);
}

char	*ft_add_str(char *str, int max, char prefix)
{
	int		i;
	char	*dest;
	char	*del;

	i = 0;
	del = str;
	if (!(dest = ft_memalloc(max + 1)))
		exit(0);
	while (i < max && max - i > (int)ft_strlen(str))
		dest[i++] = ' ';
	while (*str)
		dest[i++] = *(str++);
	dest[i] = '\0';
	if (prefix && prefix == '-')
		free(--del);
	else
		free(del);
	return (dest);
}

char	*ft_add_null(void)
{
	char	*dest;

	if (!(dest = ft_memalloc(7)))
		exit(0);
	dest[0] = '(';
	dest[1] = 'n';
	dest[2] = 'u';
	dest[3] = 'l';
	dest[4] = 'l';
	dest[5] = ')';
	dest[6] = '\0';
	return (dest);
}

char	*ft_add_np(char c)
{
	char	*dest;
	int		i;

	i = 0;
	if (!(dest = ft_memalloc(c ? 2 : 3)))
		exit(0);
	if (c)
		dest[i++] = c;
	else
	{
		dest[i++] = '^';
		dest[i++] = '@';
	}
	dest[i] = '\0';
	return (dest);
}
