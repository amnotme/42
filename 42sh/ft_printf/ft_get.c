/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 00:32:23 by brabo-hi          #+#    #+#             */
/*   Updated: 2017/12/23 21:22:59 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get.h"

int		ft_get_type(char *str, t_cs *cs)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (TYPE(str[i]))
		{
			if (TYPE_UP(str[i]))
				cs->modifier2 = 'l';
			cs->type = TYPE_UP(str[i]) ? ft_tolower(str[i]) : str[i];
			return (1);
		}
		i++;
	}
	return (-1);
}

int		ft_get_flags(char *str, t_cs *cs)
{
	int	i;
	int	t;

	i = 0;
	t = 0;
	while (str && str[i] && !TYPE(str[i]) && str[i] != '.')
	{
		if (ft_isdigit(str[i]) && str[i] != '0')
			break ;
		if (FLAGS(str[i]))
			t = 1;
		if (str[i] == '#')
			cs->flag1 = str[i];
		if (str[i] == '0')
			cs->flag2 = str[i];
		if (str[i] == '-')
			cs->flag3 = str[i];
		if (str[i] == '+')
			cs->flag4 = str[i];
		if (str[i] == ' ')
			cs->flag5 = str[i];
		i++;
	}
	return (t ? 1 : 0);
}

int		ft_get_width(char *str, t_cs *cs)
{
	int	i;

	i = 0;
	while (str && str[i] && !TYPE(str[i]))
	{
		if ((int)ft_isdigit((int)str[i]))
			cs->width = (cs->width * 10) + (str[i] - '0');
		if (str[i] == '$')
			cs->width = 0;
		if (str[i] == '.')
			break ;
		i++;
	}
	return (cs->width);
}

int		ft_get_prec(char *str, t_cs *cs)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] != '.')
		i++;
	if (str[i] && str[i] == '.')
	{
		i++;
		while (ft_isdigit((int)str[i]))
			cs->precision = (cs->precision * 10) + (str[i++] - '0');
		cs->digit = 1;
	}
	return (cs->precision);
}

int		ft_get_mod(char *str, t_cs *cs)
{
	int	i;

	i = 0;
	while (!TYPE(str[i]))
		i++;
	if (i-- && (str[i] == 'j' || str[i] == 'z'))
	{
		if (cs->modifier2)
			cs->modifier1 = str[i];
		else
			cs->modifier2 = str[i];
		return (cs->modifier1 ? 2 : 1);
	}
	if (str[i] == 'h' || str[i] == 'l')
	{
		if ((str[i - 1] == 'h' || str[i - 1] == 'l') && (str[i - 1] == str[i]))
		{
			cs->modifier1 = str[i];
			cs->modifier2 = str[i - 1];
			return (2);
		}
		cs->modifier2 = cs->modifier2 ? cs->modifier2 : str[i];
		return (cs->modifier1 ? 2 : 1);
	}
	return (0);
}
