/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 10:37:03 by lhernand          #+#    #+#             */
/*   Updated: 2018/02/09 12:14:59 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

typedef struct			s_mlx
{
	void				*mlx;
	void				*win;
	void				*data;
}						t_mlx;

typedef	struct			s_main
{
	t_mlx				mlx;
}						t_main;


int		main(void)
{

	t_main *main;
	main = (t_main *)malloc(sizeof(t_main));
	main->mlx.mlx = mlx_init();
	main->mlx.win = mlx_new_window(main->mlx.mlx, 500, 500, "wolf3d");
	main->mlx.data = mlx_new_image(main->mlx.mlx, 500, 500);


	mlx_loop(main->mlx.mlx);
	printf("it compiles\n");
	return (0);
}
