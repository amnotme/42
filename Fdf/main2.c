/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leopoldohernandez <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 22:31:33 by leopoldoh         #+#    #+#             */
/*   Updated: 2017/12/16 22:54:21 by leopoldoh        ###   ########.fr       */
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
    if (keycode == 65307)
        exit (0);
    (void)(e);
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
            mlx_pixel_put(mlx, win, x, y, 0xFF00FF);
            x++;
        }
        y++;
        usleep(500);
    }

}

int                     main(int argc, char **argv)
{
    t_env e;

    e.mlx = mlx_init();
    if (argc == 1)
        e.win = mlx_new_window(e.mlx, 500, 500, "fdf");
    else if (argc == 2)
        e.win = mlx_new_window(e.mlx, ft_atoi(argv[1]), ft_atoi(argv[2]), "fdf");
    else
        return (-1);
    //draw(e.mlx, e.win);

    mlx_loop(e.mlx);
    return (0);
}
