/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 03:57:41 by lhernand          #+#    #+#             */
/*   Updated: 2017/11/09 12:56:03 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_atoi() function converts the initial portion of the string pointed to
** by str to int representation.
*/

int		ft_atoi(const char *str)
{
	int i;
	int n;
	int sign;

	i = 0;
	n = 0;
	sign = 1;
	ft_atoi_handle(str, &i);
	if (str[i] == '-')
	{
		if ((str[i + 1] == '-') || (str[i + 1] == '+'))
			return (0);
		i++;
		sign = -1;
	}
	if (str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if ((str[i] > '9') || (str[i] < '0'))
			return (n * sign);
		n = ((n * 10) + (str[i] - '0'));
		i++;
	}
	return (n * sign);
}
