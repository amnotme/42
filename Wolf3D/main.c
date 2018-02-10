/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 10:37:03 by lhernand          #+#    #+#             */
/*   Updated: 2018/02/10 02:16:10 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

static void				exit_error(char *str, int exit_code)
{
	ft_putendl(str);
	exit(exit_code);
}

static t_main			*setup(void)
{
	t_main *main;
	
	if (!(main = (t_main *)malloc(sizeof(t_main))))
		exit_error("Failure to allocate memory to the struct", 1);
	main->mlx.mlx = mlx_init();
	main->mlx.win = mlx_new_window(main->mlx.mlx, W_WIN, H_WIN, "wolf3d");
	main->mlx.data = mlx_new_image(main->mlx.mlx, W_WIN, H_WIN);
	return (main);
}

int		main(void)
{

	t_main *wolf;

	wolf = setup();
	hooks(wolf);
	mlx_loop(wolf->mlx.mlx);
	return (0);
}
