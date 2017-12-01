/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regien <gmalpart@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 11:58:27 by regien            #+#    #+#             */
/*   Updated: 2017/10/21 06:34:15 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int	i;

	i = 0;
	if (!(n))
		return (1);
	if (s1 && s2)
	{
		while (n > 0)
		{
			if (s1[i] != s2[i])
				return (0);
			i++;
			n--;
		}
	}
	return (1);
}
