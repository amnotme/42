/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 00:38:36 by lhernand          #+#    #+#             */
/*   Updated: 2017/12/18 14:24:38 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct		s_env
{
	void 			*mlx;
	void			*win;
	int				dimen;
	int				gap;
}					t_env;

void                draw(t_env *e)
{
	int y;
	int coord[16][2] = {
		{0, 0}, {0, 1}, {0, 2}, {0, 3},
		{1, 0}, {1, 1}, {1, 2}, {1, 3},
		{2, 0}, {2, 1}, {2, 2}, {2, 3},
		{3, 0}, {3, 1}, {3, 2}, {3, 3}
	};
	y = 0;
	while ( y < e->dimen && y < 16)
	{
		mlx_string_put(e->mlx, e->win, coord[y][1] * e->gap + 100, coord[y][0] * e->gap + 100, 0xFF0000, "p");
		y++;
	}
}

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
	else if (keycode == KEY_UP)
	{
		mlx_clear_window(e->mlx, e->win);
		e->gap += 5;
		draw(e);
	}
	else if (keycode == KEY_DOWN)
	{
		mlx_clear_window(e->mlx, e->win);
		e->gap -= 5;
		draw(e);
	}
	return (1);
}
/*
   void				drawline(void *mlx, void *win, int height, int width)
   {

   }*/


/*
void					instructions(void)
{
	t_env e2;

	e2.mlx = mlx_init();
	e2.h = 500;
	e2.w = 200;
	e2.win = mlx_new_window(e2.mlx, e2.h, e2.w, "Instructions")
	mlx_string_put(e2.mlx, e2.win, 100, 20, 0x00CC00, "LEGEND"); 	
	mlx_string_put(e2.mlx, e2.win, 20, 60, 0x00CC00, "ACTION:       BUTTON:"); 
	mlx_string_put(e2.mlx, e2.win, 100, 90, 0x00CC00, "Quit program   "); 
	mlx_string_put(e2.mlx, e2.win, 100, 120, 0x00CC00, "LEGEND"); 
	mlx_string_put(e2.mlx, e2.win, 100, 150, 0x00CC00, "LEGEND"); 
	mlx_string_put(e2.mlx, e2.win, 100, 180, 0x00CC00, "LEGEND"); 
	mlx_loop(e2.mlx);	
}
*/
int                     main(int argc, char **argv)
{
	t_env e;	

	e.mlx = mlx_init();
	e.gap = 50;
	if (argc == 1)
	{
		e.dimen = 500;
		e.win = mlx_new_window(e.mlx, e.dimen, e.dimen, "fdf");
	}
	else if (argc == 2)
	{
		if (argv[1])
		{
			e.dimen = ft_atoi(argv[1]);
		}
		e.win = mlx_new_window(e.mlx, e.dimen, e.dimen, "fdf");
	}
	else
		return (-1);

	mlx_key_hook(e.win, key_hook, &e);
	draw(&e);
	mlx_loop(e.mlx);

	//instructions();
	return (0);
}
