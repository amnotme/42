/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leopoldohernandez <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 22:31:33 by leopoldoh         #+#    #+#             */
/*   Updated: 2017/12/17 02:03:06 by leopoldoh        ###   ########.fr       */
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

    y = 200;
    while (y < 400)
    {
        x = 200;
        while (x < 400)
        {
           // mlx_pixel_put(mlx, win, x, y, 0xFF00FF);
            x++;
            if (x % 15 == 0 && y % 15 == 0)
                mlx_pixel_put(mlx, win, x , y, 0x00FF00);
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
