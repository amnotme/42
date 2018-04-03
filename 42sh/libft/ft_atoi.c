/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:40:48 by brabo-hi          #+#    #+#             */
/*   Updated: 2017/12/18 23:33:06 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		number;
	int		i;
	int		signe;

	number = 0;
	i = 0;
	signe = 0;
	while (SED(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		signe = str[i] == '-' ? 1 : 0;
		i++;
	}
	while (ft_isdigit(str[i]))
		number = (number * 10) + str[i++] - '0';
	return (signe ? -number : number);
}
