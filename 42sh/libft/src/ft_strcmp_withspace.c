/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_withspace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 04:30:11 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/04/10 21:54:47 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp_withspace(const char *s1, const char *s2)
{
	while (s1 && *s1 && *s1 == ' ')
		s1++;
	while (s2 && *s2 && *s2 == ' ')
		s2++;
	return (ft_strcmp(s1, s2));
}
