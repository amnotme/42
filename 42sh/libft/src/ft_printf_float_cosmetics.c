/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_cosmetics.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 17:32:44 by asarandi          #+#    #+#             */
/*   Updated: 2017/11/12 17:51:27 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	float_cosmetics(t_placeholder *ph)
{
	if ((*ph).sign == '-')
		string_prefix(ph, "-");
	if (((*ph).flags & FLAG_PLUS) && ((*ph).sign == '+'))
		string_prefix(ph, "+");
	if ((*ph).type == 'F')
		ft_strtoupper((char *)(*ph).output);
}

int		float_round_suffix(char *str, int f)
{
	int i;

	i = ft_strlen(str) - 1;
	if (str[i] >= '5')
	{
		str[i] = '0';
		f = 1;
	}
	while (f)
	{
		i--;
		if (i < 0)
			return (f);
		str[i] = str[i] + 1;
		if (str[i] == '9' + 1)
			str[i] = '0';
		else
			f = 0;
	}
	return (f);
}

char	*float_round_prefix(char *str, int f)
{
	char	*new;
	int		i;

	i = ft_strlen(str);
	while (f)
	{
		i--;
		if ((i < 0) && (f))
		{
			new = ft_memalloc(ft_strlen(str) + 2);
			new[0] = '1';
			ft_strcpy(&new[1], str);
			free(str);
			return (new);
		}
		str[i] = str[i] + 1;
		if (str[i] == '9' + 1)
			str[i] = '0';
		else
			f = 0;
	}
	return (str);
}
