/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   true_false.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 13:13:35 by lhernand          #+#    #+#             */
/*   Updated: 2017/10/21 19:52:45 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*true_false(unsigned int num)
{
	if (num == 0)
		return ("FALSE");
	else if (num == 1)
		return ("TRUE");
	else
		return ("Did not return 1 or 0");
}
