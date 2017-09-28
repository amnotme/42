/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 09:38:15 by lhernand          #+#    #+#             */
/*   Updated: 2017/09/25 09:38:17 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void static	handle_special_chars(char const *s, int *i)
{
	while ((s[*i] == ' ') || (s[*i] == '\v') || (s[*i] == '\t') ||
			(s[*i] == '\f') || (s[*i] == '\r') || (s[*i] == '\n'))
		(*i)++;
}	

int		ft_atoi(const char *str)
{
	int i;
	int n;
	int sign;

	i = 0;
	n = 0;
	sign = 1;
	handle_special_chars(str, &i);
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
		n = ((n * 10) +  (str[i] - '0')); 
		i++;
	}
	return (n * sign);
}

