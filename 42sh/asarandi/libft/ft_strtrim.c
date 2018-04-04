/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 18:09:32 by asarandi          #+#    #+#             */
/*   Updated: 2017/09/24 13:57:43 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	k;
	char	*m;

	k = 0;
	while ((s[k] == ' ') || (s[k] == '\n') || (s[k] == '\t'))
		k++;
	i = ft_strlen(s) - 1;
	while (((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t')))
		i--;
	i++;
	if (i == 0)
		return (ft_memalloc(1));
	if ((m = ft_memalloc(i - k + 1)) == NULL)
		return (m);
	ft_strncpy(m, &s[k], i - k);
	m[i + 1] = 0;
	return (m);
}
