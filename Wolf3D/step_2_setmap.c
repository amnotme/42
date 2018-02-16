/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_2_setmap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 02:31:00 by lhernand          #+#    #+#             */
/*   Updated: 2018/02/11 20:54:27 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

/*
** This will create the sky and the sea backgrounds. It uses a gradient
** as it reads through each line from size.  The screen is divided in two.
** The upper half uses the gradient feature while the floor has a static blue
** color
*/

static void	 sky_sea(t_main *main)
{
	int i;

	i = 0;
	while (i < (main->img.size * H_WIN / 2))
	{
	
		main->img.img[i / 4] = (SUNSET + (i * (0.000135)));
		i += 1;
	}
	printf("main->img.bp : %d\n", main->img.bp);
	while (i < (main->img.size * H_WIN))
	{
		main->img.img[i / 4] = FLOOR;
		i += 1;
	}

}

void	set_map(t_main *main)
{
	sky_sea(main);
	mlx_put_image_to_window(main->mlx.mlx, main->mlx.win, main->mlx.data, 0, 0);
}
