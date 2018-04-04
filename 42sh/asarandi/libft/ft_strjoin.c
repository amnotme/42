/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 17:59:36 by asarandi          #+#    #+#             */
/*   Updated: 2017/09/24 13:56:42 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*m;

	m = ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (m == NULL)
		return (m);
	ft_strcpy(m, s1);
	ft_strcat(m, s2);
	return (m);
}
