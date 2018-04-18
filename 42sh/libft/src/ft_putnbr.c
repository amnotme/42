/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 22:20:46 by asarandi          #+#    #+#             */
/*   Updated: 2017/09/27 12:31:46 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_len2(long n)
{
	int		i;

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

static char	*ft_itoa2(long n, char *m)
{
	int		neg;
	int		i;

	neg = 0;
	if (n < 0)
	{
		n = -n;
		neg = 1;
	}
	i = ft_itoa_len2(n) + neg;
	m[i--] = 0;
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

void		ft_putnbr(int n)
{
	char	m[200];
	int		i;

	i = 0;
	while (i < 200)
		m[i++] = 0;
	ft_itoa2(n, m);
	ft_putstr(m);
}
