/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 01:00:14 by brabo-hi          #+#    #+#             */
/*   Updated: 2017/12/23 20:58:46 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_convert.h"

char	*ft_to_left(char *str)
{
	int		i;
	int		j;
	char	*dest;
	char	*del;

	i = 0;
	j = 0;
	del = str;
	if (*str != ' ')
		return (str);
	if (!(dest = ft_memalloc((ft_strlen(str) + 1))))
		exit(0);
	while (*str == ' ' && str++)
		i++;
	while (*str)
		dest[j++] = *str++;
	while (i-- > 0)
		dest[j++] = ' ';
	dest[j] = '\0';
	free(del);
	return (dest);
}

char	*ft_to_intmax_t(va_list *args, t_cs *cs, int base)
{
	intmax_t	out;

	out = va_arg(*args, intmax_t);
	if (cs->modifier1 == 'h' && cs->modifier2 == 'h')
		out = (char)out;
	else if (cs->modifier2 == 'h')
		out = (short)out;
	else if (cs->modifier1 == 'l' && cs->modifier2 == 'l')
		out = (long long)out;
	else if (!cs->modifier1 && cs->modifier2 == 'l')
		out = (long)out;
	else if (cs->modifier2 == 'j')
		out = (intmax_t)out;
	else if (cs->modifier2 == 'z')
		out = (intmax_t)out;
	else
		out = (int)out;
	return (ft_itoa_base_intmax_t(out, base));
}

char	*ft_to_uintmax_t(va_list *args, t_cs *cs, int base)
{
	uintmax_t	out;

	out = va_arg(*args, uintmax_t);
	if (cs->modifier1 == 'h' && cs->modifier2 == 'h')
		out = (unsigned char)out;
	else if (!cs->modifier1 && cs->modifier2 == 'h')
		out = (unsigned short)out;
	else if (cs->modifier1 == 'l' && cs->modifier2 == 'l')
		out = (unsigned long long)out;
	else if (!cs->modifier1 && cs->modifier2 == 'l')
		out = (unsigned long)out;
	else if (cs->modifier2 == 'j')
		out = (uintmax_t)out;
	else if (cs->modifier2 == 'z')
		out = (size_t)out;
	else
		out = (unsigned int)out;
	return (ft_itoa_base_uintmax_t(out, base));
}

char	*ft_to_wchar_t_s(va_list *args, t_cs *cs)
{
	char	*dest;
	wchar_t	*out;

	if (cs->modifier2 == 'l' || cs->type == 'S')
		out = (wchar_t *)va_arg(*args, wchar_t *);
	else
		out = (wchar_t *)va_arg(*args, char *);
	if (!(dest = ft_memalloc(ft_strlen((char *)out) + 1)))
		exit(0);
	return (ft_memcpy(dest, out, ft_strlen((char *)out)));
}

char	*ft_to_wchar_t_c(va_list *args, t_cs *cs)
{
	char	*dest;
	wchar_t	out;

	if (cs->modifier2 == 'l' || cs->type == 'S')
		out = (wchar_t)va_arg(*args, wchar_t);
	else
		out = (unsigned char)va_arg(*args, int);
	if (!(dest = ft_memalloc(2)))
		exit(0);
	dest[0] = out;
	dest[1] = '\0';
	return (dest);
}
