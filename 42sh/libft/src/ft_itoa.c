/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 19:44:30 by asarandi          #+#    #+#             */
/*   Updated: 2017/09/24 21:51:29 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_len(long n)
{
	int i;

	if (n == 0)
		return (1);
	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n2)
{
	int		neg;
	char	*m;
	int		i;
	long	n;

	n = n2;
	neg = 0;
	if (n < 0)
	{
		n = -n;
		neg = 1;
	}
	i = ft_itoa_len(n) + neg;
	if ((m = ft_memalloc(i-- + 1)) == NULL)
		return (NULL);
	if (!n)
		m[i] = '0';
	while (n)
	{
		m[i--] = (n % 10) + '0';
		n /= 10;
	}
	if (neg)
		m[i] = '-';
	return (m);
}
