/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leopoldohernandez <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 22:31:33 by leopoldoh         #+#    #+#             */
/*   Updated: 2017/12/18 10:19:02 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct      s_env
{
    void *mlx;
    void *win;
}                   t_env;

int                 key_hook(int keycode, t_env *e)
{
    ft_putstr("key pressed -> : ");
    ft_putnbr(keycode);
    ft_putchar('\n');
    if (keycode == 53)
    {
        mlx_destroy_window(e->mlx, e->win);
        exit (0);
    }
    else if (keycode == 8)
        mlx_clear_window(e->mlx, e->win);
    return (1);
}


void                draw(void *mlx, void *win)
{
    int x;
    int y;
	int coord[12][2] = {
		{0, 0}, {0, 1}, {0, 2}, {0, 3},
		{1, 0}, {1, 1}, {1, 2}, {1, 3},
		{2, 0}, {2, 1}, {2, 2}, {2, 3},
		{3, 0}, {3, 1}, {3, 2}, {3, 3}
	};
	
    y = 0;
    while (y < 12)
    {
        x = 0;
        while (x < 2)
        {
            mlx_pixel_put(mlx, win, coord[y][x] * 50 + 10 , coord[y][x] * 50 + 10, 0x00FF00);
			x++;
        }
        y++;
        usleep(100);
    }

}

int                     main(int argc, char **argv)
{
    t_env e;
    int x;
    int y;

    x = 0;
    y = 0;
    e.mlx = mlx_init();
    if (argc == 1)
        e.win = mlx_new_window(e.mlx, 500, 500, "fdf");
    else if (argc == 3)
    {
        if (argv[1] && argv[2])
        {
            x = ft_atoi(argv[1]);
            y = ft_atoi(argv[2]);
        }
        e.win = mlx_new_window(e.mlx, x, y, "fdf");
    }
    else
        return (-1);
    draw(e.mlx, e.win);
    mlx_key_hook(e.win, key_hook, &e);
    mlx_loop(e.mlx);
    return (0);
}
