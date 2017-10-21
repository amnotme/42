/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 10:18:36 by lhernand          #+#    #+#             */
/*   Updated: 2017/10/21 02:00:33 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_isprime(unsigned int num)
{
	unsigned int i;

	i = 2;
	if ((num < 2) || (num > 2147483647))
		return (0);
	while (i < num)
	{
		if (num % i == 0)
			return (0);
		i++;
	}
	return (1);
}
