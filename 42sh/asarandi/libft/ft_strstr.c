/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 15:39:46 by asarandi          #+#    #+#             */
/*   Updated: 2017/09/21 10:32:00 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int l;
	int k;

	i = 0;
	if ((!little[i]) && (big))
		return (char *)big;
	if ((little) && (!big[i]))
		return (NULL);
	l = ft_strlen(big);
	k = ft_strlen(little);
	l -= k;
	while (i <= l)
	{
		if ((ft_strncmp(little, &big[i], k)) == 0)
			return (char *)&big[i];
		i++;
	}
	return (NULL);
}
