/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regien <gmalpart@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 21:06:57 by regien            #+#    #+#             */
/*   Updated: 2017/10/21 20:05:01 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	d;
	size_t	f;
	char	**hol;

	i = 0;
	d = 0;
	if (!s || !(hol = malloc(sizeof(char*) * (ft_wordcount(s, c) + 1))))
		return (NULL);
	while (i < ft_wordcount(s, c))
	{
		if (!(hol[i] = malloc(sizeof(char) * (ft_wordlen(&s[d], c) + 1))))
			return (NULL);
		f = 0;
		while (s[d] == c)
			d++;
		while (s[d] != c && s[d])
			hol[i][f++] = s[d++];
		hol[i][f] = '\0';
		i++;
	}
	hol[i] = NULL;
	return (hol);
}
