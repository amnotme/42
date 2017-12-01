/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrevert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regien <gmalpart@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 15:35:59 by regien            #+#    #+#             */
/*   Updated: 2017/10/21 06:36:30 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Revert every character in the string;
*/

char	*ft_strrevert(char *s1)
{
	char	*mom;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s1) - 1;
	if (!(mom = malloc((sizeof(char) * ft_strlen(s1)) + 1)))
		return (0);
	ft_strcpy(mom, s1);
	while (len > 0)
	{
		mom[i] = s1[len];
		i++;
		len--;
	}
	return (mom);
}
