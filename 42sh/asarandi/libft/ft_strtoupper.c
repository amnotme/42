/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 15:13:17 by asarandi          #+#    #+#             */
/*   Updated: 2017/09/28 15:18:48 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtoupper(char *s)
{
	size_t	i;
	size_t	k;

	i = ft_strlen(s);
	k = 0;
	while (k < i)
	{
		if ((s[k] >= 'a') && (s[k] <= 'z'))
			s[k] = ft_toupper(s[k]);
		k++;
	}
	return (s);
}
