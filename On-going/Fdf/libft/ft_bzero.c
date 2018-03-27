/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 05:24:45 by lhernand          #+#    #+#             */
/*   Updated: 2017/12/14 02:16:57 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_bzero() function writes n zeroed bytes to the string s.
** If n is zero, bzero() does nothing.
*/

void		ft_bzero(void *s, size_t n)
{
	if (n == 0)
		return ;
	ft_memset(s, 0, n);
}
