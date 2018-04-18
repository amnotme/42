/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_reset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 14:28:20 by lhernand          #+#    #+#             */
/*   Updated: 2017/12/14 02:22:31 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Makes text to the standard white. to be used after another color has been
** used.
*/

void	c_reset(void)
{
	ft_putstr("\033[0m");
}
