/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 15:39:46 by asarandi          #+#    #+#             */
/*   Updated: 2017/09/25 17:14:49 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *litl, size_t len)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	if ((!litl[i]) && (big))
		return (char *)big;
	if ((litl) && (!big[i]))
		return (NULL);
	k = ft_strlen(litl);
	j = len - k;
	if (j > ft_strlen(big))
		return (NULL);
	if ((j == 0) && (ft_strncmp(big, litl, k) == 0))
		return (char *)(big);
	while (i < j + 1)
	{
		if ((ft_strncmp(&big[i], litl, k)) == 0)
			return (char *)&big[i];
		i++;
	}
	return (NULL);
}
