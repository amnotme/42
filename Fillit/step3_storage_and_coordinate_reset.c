/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step3_storage_and_coordinate_reset.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:11:41 by lhernand          #+#    #+#             */
/*   Updated: 2017/11/30 18:41:00 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** modify the string to change the dots
*/

char			**mod_str(char **str, t_piece *dummy)
{
	int			i;

	i = -1;
	full_dots(str);
	while (++i < 4)
		str[dummy->x[i]][dummy->y[i]] = '#';
	return (str);
}

/*
** Modify the original coordinates of the tetramino file to a position
** either starting in row 0 or column 0
*/

char			**init_cero(char **str, t_piece *dummy)
{
	int			i;
	int			*point;
	int			e;

	e = -1;
	point = dummy->x;
	i = -1;
	while (++e < 2)
	{
		while (++i < 4)
		{
			if (point[i] == 0)
				break ;
			else if (i == 3 && point[i] != 0)
			{
				i = -1;
				while (++i < 4)
					point[i] -= 1;
				i = -1;
			}
		}
		point = dummy->y;
	}
	return (mod_str(str, dummy));
}

/*
** get the coordinates of the position of '#' in the 4x4 tetramino
*/

char			**get_coord(char **str, t_piece *dummy)
{
	int			x;
	int			y;
	int			e;
	int			scounter;

	e = 0;
	scounter = 0;
	x = -1;
	while (++x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (str[x][y] == '#' && scounter < 4 && e < 4)
			{
				dummy->x[e] = x;
				dummy->y[e] = y;
				scounter++;
				e++;
			}
			y++;
		}
	}
	str = init_cero(str, dummy);
	return (str);
}

/*
**  Allocate memory and create fulfill the content of the structure
*/

t_list			*create_element(char *str, int contador)
{
	t_piece		*dummy;
	int			dummycount;

	dummycount = (contador - 1);
	dummy = ft_memalloc(sizeof(t_piece));
	dummy->x = ft_memalloc(sizeof(int) * 4);
	dummy->y = ft_memalloc(sizeof(int) * 4);
	dummy->piece = get_coord(ft_strsplit(str, '\n'), dummy);
	dummy->letra = ('A' + dummycount);
	return (ft_lstnew(dummy, sizeof(t_piece)));
}

/*
** First part of the storage
** if the list is empty add a new element to the head of the list
** if not, it would add it at the back of the list
*/

void			make_piece(t_list **pieces, char *buf, int count)
{
	if (*pieces)
		ft_lstadd_back(pieces, create_element(buf, count));
	else
		*pieces = create_element(buf, count);
}
