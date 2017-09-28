/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 09:36:22 by lhernand          #+#    #+#             */
/*   Updated: 2017/09/25 09:37:02 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcat(char *restrict s1, char const *restrict s2)
{
	int		i;
	int 	l;
	char 	*ptr;

	i = 0;
	l = 0;
	ptr = s1;
	while (s1[l] != '\0')
		l++;
	while (s2[i] != '\0')
	{
		s1[l] = s2[i];
		i++;
		l++;
	}
	s1[l] = '\0';
	s1 = ptr;
	return (s1);	
}
