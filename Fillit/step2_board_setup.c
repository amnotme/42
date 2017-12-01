/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step2_board_setup.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 17:32:21 by lhernand          #+#    #+#             */
/*   Updated: 2017/11/30 18:36:16 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			full_dots(char **board)
{
	int	i;
	int	d;

	i = 0;
	d = 0;
	while (i < 4)
	{
		d = 0;
		while (d < 4)
			board[i][d++] = '.';
		i++;
	}
}

/*
** with dots, depending the size of the map.
*/

void			full_dots_dyn(char **board, int size)
{
	int i;
	int d;

	i = 0;
	d = 0;
	while (i < size)
	{
		d = 0;
		while (d < size)
			board[i][d++] = '.';
		i++;
	}
}

int				verify_map(char **board, int size)
{
	int	x;
	int y;

	x = -1;
	while (++x < size)
	{
		y = -1;
		while (++y < size)
			if (board[x][y] != '.')
				return (0);
	}
	return (1);
}

/*
** Star generating the board
*/

char			**gen_board(int size)
{
	char		**board;
	int			i;

	i = -1;
	board = ft_memalloc(sizeof(char *) * size);
	while (++i < size)
	{
		board[i] = ft_memalloc(sizeof(char) * size);
		board[i][size] = '\0';
	}
	full_dots_dyn(board, size);
	return (board);
}

/*
** Print the final map with the size of the square
** dyn = dynamically.
*/

void			print_board_dyn(char **board, int size)
{
	int i;

	if (verify_map(board, size) == 1)
		fillit_print_error(-1);
	i = -1;
	while (++i < size)
	{
		ft_putstr(board[i]);
		ft_putchar('\n');
	}
}
