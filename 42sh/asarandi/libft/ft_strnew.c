/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 16:07:37 by asarandi          #+#    #+#             */
/*   Updated: 2017/09/24 13:56:10 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*p;
	size_t			i;

	if ((p = (char *)malloc(size * sizeof(char) + 1)) == NULL)
		return (NULL);
	i = 0;
	while (i <= size)
		p[i++] = 0;
	return (char *)(p);
}
