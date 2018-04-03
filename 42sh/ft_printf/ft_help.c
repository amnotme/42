/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 20:48:18 by brabo-hi          #+#    #+#             */
/*   Updated: 2017/12/23 23:09:32 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_help.h"

char	*ft_add_prefix_help(char *out, char prefix1, char prefix2)
{
	int		i;
	char	*dest;
	char	*del;

	i = 0;
	del = out;
	if (!(dest = ft_memalloc(ft_strlen(out) + 1 + (prefix2 ? 1 : 0))))
		exit(0);
	dest[i++] = prefix1;
	if (prefix2)
		dest[i++] = prefix2;
	while (out && *out)
		dest[i++] = *out++;
	dest[i] = '\0';
	free(del);
	return (dest);
}

char	ft_set_d_help(char *out, t_cs *cs)
{
	char	p;

	p = 0;
	if (*out == '-')
		p = '-';
	if (*out != '-' && cs->flag5)
		p = ' ';
	if (*out != '-' && cs->flag4)
		p = '+';
	return (p);
}

char	*ft_to_upper_x(char *dest)
{
	int	i;

	i = -1;
	while (++i < (int)ft_strlen(dest))
		dest[i] = (char)ft_toupper(dest[i]);
	return (dest);
}
