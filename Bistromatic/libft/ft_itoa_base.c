/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:30:10 by lhernand          #+#    #+#             */
/*   Updated: 2018/01/09 16:03:19 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Takes an int, and converts it to a null-terminated string, with a specific
** numeric base (from binary to hexadecimal).
*/

char		*ft_itoa_base(int value, int base)
{
	long	nbr;
	int		len;
	char	*pointer;
	char	*base_string;

	if (value == 0 || base < 2 || base > 16)
		return (ft_strdup("0"));
	nbr = value;
	len = ft_numlength(nbr, base);
	base_string = "0123456789ABCDEF";
	nbr < 0 ? nbr *= -1 : 0;
	if (!(pointer = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	pointer[len] = '\0';
	while (nbr)
	{
		pointer[--len] = base_string[nbr % base];
		nbr /= base;
	}
	if ((value < 0) && (base == 10))
		pointer[0] = '-';
	return (pointer);
}
