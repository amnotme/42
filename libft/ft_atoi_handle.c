/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.us.42.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 19:44:25 by lhernand          #+#    #+#             */
/*   Updated: 2017/10/21 01:49:42 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_atoi_handle(const char *s, int *i)
{
	while ((s[*i] == ' ') || (s[*i] == '\v') || (s[*i] == '\t') ||
			(s[*i] == '\f') || (s[*i] == '\r') || (s[*i] == '\n'))
		(*i)++;
}
