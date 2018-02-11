/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 10:38:50 by lhernand          #+#    #+#             */
/*   Updated: 2018/02/11 04:08:49 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "key_code.h"
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <math.h>
//# include "mlx.h"
# include <mlx.h>
/*
** Structs used
*/

typedef struct				s_mlx
{
	void					*mlx;
	void					*win;
	void					*data;
}							t_mlx;

typedef struct				s_img
{
	int						*img; // might need to make it int
	int						bp;
	int						size;
	int						endian;
}							t_img;

typedef	struct				s_main
{
	t_mlx					mlx;
	t_img					img;
}							t_main;



/*
** For testing purposes we'll define a global int array map
*/

extern int		global_map[10][10];

/*
** Macros used for window width and height
*/

# define W_WIN 1280
# define H_WIN 720

/*
** Macros for colors
*/

# define SUNSET (0x00f2671f)
# define FLOOR  (0x02cad8ff)

/*
** Function prototypes
*/

void				hooks(t_main *main);
void				set_map(t_main *main);

#endif
