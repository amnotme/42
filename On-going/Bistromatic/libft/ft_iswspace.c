/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswspace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 21:17:13 by lhernand          #+#    #+#             */
/*   Updated: 2017/11/09 16:00:53 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_iswspace() function returns a non-zero number to indicate for a
** truthy value
*/

int			ft_iswspace(int c)
{
	return (c == '\t' || c == ' ' || c == '\n');
}
