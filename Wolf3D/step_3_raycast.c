/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_3_raycast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 00:23:35 by lhernand          #+#    #+#             */
/*   Updated: 2018/02/12 01:57:59 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		walls(t_main *main)
{
	int i;
	int color;
	float temp;
	float line;

	i = 0;
	main->wall.angle = (main->player.angle / 180) * M_PI;
	while (i < W_WIN)
	{
		temp = (W_WIN / 2);
		temp = temp - ((float)i / W_WIN);
		main->wall.x = cos(main->wall.angle) - temp * sin(main->wall.angle);
		main->wall.y = sin(main->wall.angle) + temp * cos(main->wall.angle);
		main->wall.x = main->wall.x + main->player.cam_x;
		main->wall.y = main->wall.y + main->player.cam_y;
		i++;
	}
}



/*
** Raycasting. Create ray from eye towards objects
** Determines teh color of the ray using light from the information
** Pixel color of the image is the color of the ray (passing through the pixel)
*/
void			raycasting(t_main *main, int *shade)
{

}
