/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regien <gmalpart@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 20:23:03 by regien            #+#    #+#             */
/*   Updated: 2017/10/21 09:01:28 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int n, int base)
{
	long	nbr;
	int		len;
	char	*holder;
	char	*base_string;

	base_string = "0123456789ABCDEF";
	if (n == 0 || base < 2 || base > 16)
		return (ft_strdup("0"));
	nbr = n;
	len = ft_nbrlen(nbr, base);
	if (!(holder = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	holder[len] = '\0';
	if (nbr < 0)
		nbr = nbr * -1;
	while (nbr)
	{
		holder[--len] = base_string[nbr % base];
		nbr = nbr / base;
	}
	if ((n < 0) && (base == 10))
		holder[0] = '-';
	return (holder);
}
