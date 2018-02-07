/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   true_false.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 13:13:35 by lhernand          #+#    #+#             */
/*   Updated: 2017/11/09 16:43:23 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The true_false() will output 'FALSE' if the number passed is 0, 'TRUE' if
** the number is 1 and 'Did not return 1 or 0 for any other number.
*/

char		*true_false(unsigned int num)
{
	if (num == 0)
		return ("FALSE");
	else if (num == 1)
		return ("TRUE");
	else
		return ("Did not return 1 or 0");
}
