/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step4_backtracking.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 17:52:21 by lhernand          #+#    #+#             */
/*   Updated: 2017/11/30 18:03:01 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Recursive backtracking,
** if not valid solution is found, it return 0 and *look solver*
** increase size by one.
*/

int				backtrack(t_board *board, t_list *pieces)
{
	int			x;
	int			y;
	t_piece		*iterdata;

	if (!pieces)
		return (1);
	iterdata = pieces->content;
	x = -1;
	while (++x < board->size)
	{
		y = -1;
		while (++y < board->size)
			if ((check_valid_position(board, pieces, x, y)) == 1)
			{
				board->board = put_piece(board->board, pieces, x, y);
				if (backtrack(board, pieces->next))
					return (1);
				else
					board->board = remove_piece(board->board, pieces, x, y);
			}
	}
	return (0);
}

/*
** First step of the inner backtracking work
** Before emplacing the piece we veriffy that is a valid position
*/

int				check_valid_position(t_board *mapa, \
				t_list *piezas, int x, int y)
{
	t_piece		*iterdata;
	int			i;

	i = -1;
	iterdata = piezas->content;
	while (++i < 4)
	{
		if ((iterdata->x[i] + x) >= mapa->size)
			return (0);
		if ((iterdata->y[i] + y) >= mapa->size)
			return (0);
		if (mapa->board[iterdata->x[i] + x][iterdata->y[i] + y] != '.')
			return (0);
	}
	return (1);
}

/*
** Second step of the inner backtracking work
** emplace the piece if it's a valid position
*/

char			**put_piece(char **mapa, t_list *piezas, int x, int y)
{
	t_list		*iter;
	t_piece		*iterdata;
	int			i;

	i = -1;
	iter = piezas;
	iterdata = iter->content;
	while (++i < 4)
		mapa[iterdata->x[i] + x][iterdata->y[i] + y] = iterdata->letra;
	return (mapa);
}

/*
** Third step of the inner backtracing work
** At some point the backtracking will return you 0 so the program
** now knows where is the failure so it will unplace that piece and
** continue calling the function.
*/

char			**remove_piece(char **mapa, t_list *piezas, int x, int y)
{
	t_list		*iter;
	t_piece		*iterdata;
	int			i;

	i = -1;
	iter = piezas;
	iterdata = iter->content;
	while (++i < 4)
		mapa[iterdata->x[i] + x][iterdata->y[i] + y] = '.';
	return (mapa);
}

/*
** Final part
** Solver first set the size of the map after getting the size
** Then execute the backtrack, if somehow the backtrack return 0
** then increase the size by oneand then try again.
*/

t_board			*solver(t_list *pieces, t_board *mapa)
{
	if (mapa->valid == 1)
		fillit_print_error(READ_ERROR);
	mapa->size = square_root(mapa->size * 4);
	mapa->board = gen_board(mapa->size);
	while (!backtrack(mapa, pieces))
	{
		mapa->size++;
		mapa->board = gen_board(mapa->size);
	}
	return (mapa);
}
