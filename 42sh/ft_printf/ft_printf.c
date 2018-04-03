/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 19:43:18 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/04 23:36:11 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_format(char *str, va_list *args)
{
	char	*dest;
	t_cs	*cs;
	int		i;

	i = 0;
	if (!(cs = ft_memalloc(sizeof(t_cs))))
		exit(0);
	while (i < 5)
		if (((*g_gets[i++].f)(str, cs)) == -1)
			return (NULL);
	i = 0;
	while (i < 15)
	{
		if (cs->type && cs->type == g_sets[i].type)
		{
			dest = (*g_sets[i].f)(args, cs);
			free(cs);
			return (dest);
		}
		i++;
	}
	return (NULL);
}

int		ft_printf(const char *str, ...)
{
	va_list	args;
	char	*dest;
	char	*out;

	va_start(args, str);
	if (!(dest = NULL) && !ft_is_valid((char *)str))
		return (0);
	while (str && *str)
	{
		if (*str == '%' && str++)
		{
			out = ft_format((char *)str, &args);
			if (!(dest = ft_concat(dest, out, 0)))
				return (-1);
			free(out);
			while (!TYPE(*str))
				str++;
			str++;
		}
		if (str && *str != '%' && *str != '\0')
			if ((!(dest = ft_concat(dest, (char *)str++, 1))))
				return (-1);
	}
	va_end(args);
	return (ft_display(dest));
}
