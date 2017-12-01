/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regien <gmalpart@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 18:51:57 by regien            #+#    #+#             */
/*   Updated: 2017/10/21 09:39:46 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Allocates memory and returns an array of "fresh" string
**	with no spaces( ' ' / '\n' / '\t') at the begining and
**	the end, if not gives you NULL
*/

static size_t	get_x(char const *s1)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == ' ' || s1[i] == '\n' || s1[i] == '\t')
			i++;
		if (s1[i] != ' ' && s1[i] != '\n' && s1[i] != '\t' \
				&& s1[i] != '\0')
			break ;
	}
	return (i);
}

static size_t	get_y(char const *s2)
{
	size_t	i;

	i = 0;
	if (!(*s2))
		return (i);
	i = (ft_strlen(s2) - 1);
	while (i > 0)
	{
		if (s2[i] == ' ' || s2[i] == '\n' || s2[i] == '\t')
			i--;
		if (s2[i] != ' ' && s2[i] != '\n' && s2[i] != '\t' \
				&& s2[i] != '\0')
			break ;
	}
	return (i);
}

char			*ft_strtrim(char const *s)
{
	size_t	x;
	size_t	y;
	size_t	cont;
	char	*tempstr;

	if (!s)
		return (NULL);
	cont = 0;
	x = get_x(s);
	y = get_y(s);
	if (x != ft_strlen(s) || y != 0)
	{
		if (!(tempstr = malloc((sizeof(char) * ((y - x) + 2)))))
			return (NULL);
		while (x <= y)
		{
			tempstr[cont] = s[x];
			x++;
			cont++;
		}
		tempstr[cont] = '\0';
		return (tempstr);
	}
	return (ft_strnew(1));
}
