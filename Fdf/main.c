/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 00:38:36 by lhernand          #+#    #+#             */
/*   Updated: 2017/12/18 02:50:47 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct		s_env
{
	void *mlx;
	void *win;
	int 	w;
	int 	h;
}					t_env;

int                 key_hook(int keycode, t_env *e)
{
	ft_putstr("key pressed -> : ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit (0);
	}
	else if (keycode == KEY_C)
		mlx_clear_window(e->mlx, e->win);
	//else if (keycode == KEY_UP)

	return (1);
}
/*
void				drawline(void *mlx, void *win, int height, int width)
{
	
}*/

void                draw(void *mlx, void *win, int height, int width)
{
	int x;
	int y;

	y = 0;
	while (y <= width)
	{
		x = 0;
		while (x <= height)
		{
			x++;
			if (x % 25 == 0 && y % 25 == 0)
				mlx_pixel_put(mlx, win, x , y, 0x00FF00);
		}
		y++;
	}
}

void					instructions(void)
{
	t_env e2;

	e2.mlx = mlx_init();
	e2.h = 500;
	e2.w = 200;
	e2.win = mlx_new_window(e.mlx, e2.h, e2.w, "Instructions");
	mlx_string_put(e2.mlx, e2.win, 100, 20, 0x00CC00, "LEGEND"); 	
	mlx_string_put(e2.mlx, e2.win, 20, 60, 0x00CC00, "ACTION:         BUTTON:"); 
	mlx_string_put(e2.mlx, e2.win, 100, 90, 0x00CC00, "Quit program   "); 
	mlx_string_put(e2.mlx, e2.win, 100, 120, 0x00CC00, "LEGEND"); 
	mlx_string_put(e2.mlx, e2.win, 100, 150, 0x00CC00, "LEGEND"); 
	mlx_string_put(e2.mlx, e2.win, 100, 180, 0x00CC00, "LEGEND"); 
	mlx_loop(e2.mlx);	
}

int                     main(int argc, char **argv)
{
	t_env e;	

	e.mlx = mlx_init();
	if (argc == 1)
	{
		e.h = 500;
		e.w = 500;
		e.win = mlx_new_window(e.mlx, e.h, e.w, "fdf");
	}
	else if (argc == 3)
	{
		if (argv[1] && argv[2])
		{
			e.h = ft_atoi(argv[1]);
			e.w = ft_atoi(argv[2]);
		}
		e.win = mlx_new_window(e.mlx, e.h, e.w, "fdf");
	}
	else
		return (-1);

	draw(e.mlx, e.win, e.w, e.h);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);

	instructions();
	return (0);
}
