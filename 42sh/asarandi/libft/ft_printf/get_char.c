/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:38:04 by asarandi          #+#    #+#             */
/*   Updated: 2017/11/12 17:46:01 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** uncomment this function to print multi-byte utf8 sequences
** (passes moulitest)
**
**unsigned char	*get_wchar(va_list *ap, t_placeholder *ph)
**{
**	unsigned char	buffer[5];
**	unsigned int	wchar;
**	unsigned char	*result;
**	int				i;
**
**	i = 0;
**	while (i < 5)
**		buffer[i++] = 0;
**	wchar = (unsigned int)va_arg(*ap, wchar_t);
**	(*ph).char_count = wchar_to_utf8(wchar, buffer);
**	if ((result = ft_memalloc(8)) == NULL)
**		return (NULL);
**	i = 0;
**	while (i < 5)
**	{
**		result[i] = buffer[i];
**		i++;
**	}
**	return (result);
**}
*/

unsigned char	*get_wchar(va_list *ap, t_placeholder *ph)
{
	wchar_t			*result;

	if ((result = ft_memalloc(sizeof(wchar_t) * 2)) == NULL)
		return (NULL);
	result[0] = (wchar_t)va_arg(*ap, wint_t);
	result[1] = 0;
	(*ph).char_count = 1;
	return ((unsigned char *)result);
}

unsigned char	*get_char(va_list *ap, t_placeholder *ph)
{
	unsigned char	*c;

	if ((*ph).length > 32)
		return (get_wchar(ap, ph));
	if ((c = ft_memalloc(4)) == NULL)
		return (NULL);
	c[0] = (unsigned char)va_arg(*ap, int);
	(*ph).char_count = 1;
	return (c);
}

int				get_wstr_length(wchar_t *wstr)
{
	int				result;
	wchar_t			c;
	unsigned char	buffer[5];

	c = 0;
	result = 0;
	while (wstr[c])
	{
		result += wchar_to_utf8(wstr[c], buffer);
		c++;
	}
	return (result);
}

unsigned char	*get_wide_string(va_list *ap, t_placeholder *ph)
{
	wchar_t			*wstr;
	wchar_t			wchar;
	int				length;
	unsigned char	*output;
	int				i;

	wstr = va_arg(*ap, wchar_t *);
	if (wstr == NULL)
	{
		(*ph).char_count = 6;
		return ((unsigned char *)ft_strdup("(null)"));
	}
	length = get_wstr_length(wstr);
	if ((output = ft_memalloc(length + 8)) == NULL)
		return (NULL);
	wchar = 0;
	i = 0;
	while (wstr[wchar])
	{
		i += wchar_to_utf8(wstr[wchar], &output[i]);
		wchar++;
	}
	(*ph).char_count = i;
	return (output);
}

unsigned char	*get_string(va_list *ap, t_placeholder *ph)
{
	unsigned char	*str;
	unsigned char	*result;

	if ((*ph).length > 32)
		return (get_wide_string(ap, ph));
	str = va_arg(*ap, unsigned char *);
	if (str == NULL)
		result = (unsigned char *)ft_strdup("(null)");
	else
		result = (unsigned char *)ft_strdup((char *)str);
	(*ph).char_count = ft_strlen((char *)result);
	return (result);
}
