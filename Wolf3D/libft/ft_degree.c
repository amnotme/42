/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_degree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 01:02:50 by lhernand          #+#    #+#             */
/*   Updated: 2018/02/10 01:22:53 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Handles degrees below 0 and above 360
*/

int				ft_degree(int angle)
{
	if (angle < 0)
		angle = angle * -1;
	if (angle > 360)
		angle = angle % 360;
	return (angle);
}
