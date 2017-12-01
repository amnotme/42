/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regien <gmalpart@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 01:42:46 by regien            #+#    #+#             */
/*   Updated: 2017/10/21 06:21:58 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	counts the words in a string, using a char as a separator.
*/

size_t		ft_wordcount(const char *str, char n)
{
	int		i;
	size_t	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (str[i] != n)
			words++;
		while (str[i] != n && str[i + 1])
			i++;
		i++;
	}
	return (words);
}
