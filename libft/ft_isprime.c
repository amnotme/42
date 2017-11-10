/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 10:18:36 by lhernand          #+#    #+#             */
/*   Updated: 2017/11/09 16:41:18 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_isprime() function verifies if a number is a prime or not.
**
** If the number is prime it returns a 1 otherwise returns 0.
*/

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
