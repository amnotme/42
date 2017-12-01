/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regien <gmalpart@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 20:18:32 by regien            #+#    #+#             */
/*   Updated: 2017/10/21 06:46:32 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	int		i;
	char	*holder;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	if (!(holder = (char *)malloc(sizeof(*s) * (len + 1))))
		return (NULL);
	while (s[i])
	{
		holder[i] = f(s[i]);
		i++;
	}
	holder[i] = '\0';
	return (holder);
}
