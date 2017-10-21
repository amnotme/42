/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 22:01:49 by lhernand          #+#    #+#             */
/*   Updated: 2017/10/19 19:27:31 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	size_t	i;
	size_t	n_s;
	char	*str;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	n_s = ft_numlength(n, 10);
	if (!(str = (char *)malloc(sizeof(char) * (n_s + 1))))
		return (NULL);
	str[n_s] = 0;
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;;
		i++;
	}
	while (i < n_s--)
	{
		str[n_s] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
