/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 15:16:29 by asarandi          #+#    #+#             */
/*   Updated: 2017/09/28 15:18:03 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtolower(char *s)
{
	size_t	i;
	size_t	k;

	i = ft_strlen(s);
	k = 0;
	while (k < i)
	{
		if ((s[k] >= 'A') && (s[k] <= 'Z'))
			s[k] = ft_tolower(s[k]);
		k++;
	}
	return (s);
}
