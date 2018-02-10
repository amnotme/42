/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_1_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 01:28:57 by lhernand          #+#    #+#             */
/*   Updated: 2018/02/10 02:12:04 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int		esc_hook(t_main *main)
{
	mlx_destroy_window(main->mlx.mlx, main->mlx.win);
	exit(0);
}

static int		pressed_hook(int key, t_main *main)
{
	if (key == KEY_ESC)
		esc_hook(main);
	return (0);
}


void			hooks(t_main *main)
{
	mlx_hook(main->mlx.win, 2, 0, pressed_hook, main);
//	mlx_hook(main->mlx.win, 17, 0, esc_hook, main); ???
}
