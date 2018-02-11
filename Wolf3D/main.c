/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 10:37:03 by lhernand          #+#    #+#             */
/*   Updated: 2018/02/11 04:08:53 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

int	global_map[10][10] =
{
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
	{4, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{4, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{4, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{4, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{4, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{4, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{4, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{4, 0, 0, 0, 0, 0, 0, 0, 0, 2},
	{4, 3, 3, 3, 3, 3, 3, 3, 3, 3}
};

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
	main->img.img = (int *)mlx_get_data_addr(main->mlx.data, &main->img.bp, \
		&main->img.size, &main->img.endian); //might need to cast it to int *	
	return (main);
}

int						main(void)
{

	t_main *wolf;

	wolf = setup();
	hooks(wolf);
	set_map(wolf);
	mlx_loop(wolf->mlx.mlx);
	return (0);
}
