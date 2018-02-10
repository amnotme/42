/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 10:38:50 by lhernand          #+#    #+#             */
/*   Updated: 2018/02/10 01:52:51 by lhernand         ###   ########.fr       */
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

typedef	struct				s_main
{
	t_mlx					mlx;
}							t_main;

/*
** Macros used for window width and height
*/

# define W_WIN 600
# define H_WIN 1200

/*
** Function prototypes
*/

void				hooks(t_main *main);

#endif
