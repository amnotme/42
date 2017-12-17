/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 00:38:36 by lhernand          #+#    #+#             */
/*   Updated: 2017/12/16 19:18:54 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <mlx.h>

typedef struct		s_env
{
	void *mlx;
	void *win;
}					t_env;

void				draw(void *mlx, void *win)
{
	int	x;
	int y;

	y = 100;
	while (y < 200)
	{
		x = 100;
		while (x < 200)
		{
			mlx_pixel_put(mlx, win, x, y, 0xFF0000);
			x++;
		}
		y++;
	}
}

int					expose_hook(t_env *e)
{
	draw(e->mlx, e->win);
	return (0);
}


int					key_hook(int keycode, t_env *e)
{
	ft_putendl("Keycode: ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == 65307)
		exit (0);
	(void )(e);
	return (0);
}



int 				main(void)
{
	t_env e;
	
	
	e.mlx = mlx_init();
	//if (argc == 1)		
		e.win = mlx_new_window(e.mlx, 420, 420, "title");
	//else if (argc == 3)
	/*{
		e.win = mlx_new_window(e.mlx, ft_atoi(argv[1]), ft_atoi(argv[2]) \
				,argv[2]);	
	}*/
	mlx_key_hook(e.win, key_hook, &e);

//	draw(e.mlx, e.win);
	mlx_loop(e.mlx);
	
	return (0);
}
