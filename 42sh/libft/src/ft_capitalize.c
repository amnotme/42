/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capitalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 13:54:17 by asarandi          #+#    #+#             */
/*   Updated: 2017/09/28 13:03:28 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_capitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
		{
			str[i] = ft_toupper(str[i]);
			i++;
			while (ft_isalpha(str[i]))
			{
				str[i] = ft_tolower(str[i]);
				i++;
			}
		}
		i++;
	}
	return (str);
}
