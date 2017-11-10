/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 21:58:13 by lhernand          #+#    #+#             */
/*   Updated: 2017/11/09 13:49:42 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Sets every character of the string to the value ’\0’.
*/

void		ft_strclr(char *s)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i])
			s[i++] = '\0';
	}
}
