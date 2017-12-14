/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_odd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 13:02:12 by lhernand          #+#    #+#             */
/*   Updated: 2017/11/09 16:49:59 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This ft_odd() function takes a valid integer and returns 1 if it's an odd
** number, otherwise it returns 0.
*/

int		ft_odd(int num)
{
	if ((num <= 2147483647) && (num > -2147483648))
	{
		if (num % 2 == 1)
			return (1);
	}
	return (0);
}
