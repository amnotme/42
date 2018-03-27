/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 22:22:22 by lhernand          #+#    #+#             */
/*   Updated: 2017/11/09 14:01:10 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Applies the function f to each character of the string passed
** as argument by giving its index as first argument to create a
** “fresh” new string (with malloc(3)) resulting from the successive
** applications of f.
**
** Returns the “fresh” string created from the successive applications of f.
*/

char		*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	if (!s)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char ) * ft_strlen(s) + 1)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
