/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 15:37:35 by asarandi          #+#    #+#             */
/*   Updated: 2018/02/11 06:13:38 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *s)
{
	int		i;
	int		n;
	long	r;

	i = 0;
	n = 0;
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '+')
		i++;
	else if (s[i] == '-')
		n = ++i;
	r = 0;
	while (ft_isdigit(s[i]))
		r = (r * 10) + s[i++] - '0';
	if (n)
		return ((int)-r);
	else
		return ((int)r);
}
