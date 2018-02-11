/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_2_setmap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 02:31:00 by lhernand          #+#    #+#             */
/*   Updated: 2018/02/11 04:07:50 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	 sky_land(t_main *main)
{
	int i;

	i = 0;
	while (i < (main->img.size * H_WIN / 2))
	{
		main->img.img[i / 4] = (SUNSET + (i * (0.000135)));
		i += 1;
	}
	while (i < (main->img.size * H_WIN))
	{
		main->img.img[i / 4] = FLOOR;
		i += 1;
	}
}

void	set_map(t_main *main)
{
	sky_land(main);
	mlx_put_image_to_window(main->mlx.mlx, main->mlx.win, main->mlx.data, 0, 0);
}
