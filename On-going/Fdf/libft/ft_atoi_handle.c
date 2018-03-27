/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.us.42.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 19:44:25 by lhernand          #+#    #+#             */
/*   Updated: 2017/11/09 12:57:39 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_atoi_handle() functions is a helper function for ft_atoi(). It allows
** for the first check of white spaces and helps the code stay DRY.
*/

void		ft_atoi_handle(const char *s, int *i)
{
	while ((s[*i] == ' ') || (s[*i] == '\v') || (s[*i] == '\t') ||
			(s[*i] == '\f') || (s[*i] == '\r') || (s[*i] == '\n'))
		(*i)++;
}
