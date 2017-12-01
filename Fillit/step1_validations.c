/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step1_validations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:53:02 by lhernand          #+#    #+#             */
/*   Updated: 2017/12/01 01:35:41 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int g_o[3][19] = {
	{5, 1, 1, 1, 3, 5, 1, 1, 1, 5, 5, 4, 5, 1, 4, 5, 1, 1, 4},
	{10, 2, 5, 6, 4, 10, 2, 5, 2, 9, 6, 5, 6, 2, 5, 6, 4, 6, 5},
	{15, 3, 6, 11, 5, 11, 5, 10, 7, 10, 7, 6, 10, 6, 10, 11, 5, 7, 9}
};

/*
** Verifies each tetramino by looking at all possible offsets. each
** offset trio denotes a given tetramino piece. if all three
** offsets check that there is a hash and returns true. Then the
** the tetramino is valid.
*/

int				verify_valid_tetraminos(char *data)
{
	int i;
	int j;
	int z;

	i = 0;
	j = -1;
	z = i;
	while ((data[z] != '#') && (((z - i) + j) < 21))
		z++;
	while (++j < 19)
	{
		if (data[z] == '#' && data[z + g_o[0][j]] == '#' && \
				data[z + g_o[1][j]] == '#' && data[z + g_o[2][j]] == '#')
		{
			i += 21;
			break ;
		}
	}
	if (j == 19)
		return (FALSE);
	return (TRUE);
}

/*
** We verify each piece's FORMAT that is that every single enterin tet
** contains 12 dots 4 hashes and 4 newlines and that each newline is
** positioned after 4 dots.
** The functions returns true if all add-up to 20 characters and the
** last character is a null character.
*/

int				verify_piece(char *data)
{
	int newlines;
	int hashes;
	int dots;
	int i;

	i = 0;
	newlines = 0;
	hashes = 0;
	dots = 0;
	while (data[i] && i < 20)
	{
		if ((data[i] == '\n') && ((i + 1) % 5 == 0))
			newlines++;
		else if (data[i] == '.')
			dots++;
		else if (data[i] == '#')
			hashes++;
		i++;
	}
	return ((data[i] == '\0') \
			&& (newlines == 4 && hashes == 4 && dots == 12) ? TRUE : FALSE);
}

/*
** Verify that the next thing after a valid tetramino is a '\n'
*/

int				val_nl(char *buf, int fd, int *ret)
{
	ft_strclr(buf);
	*ret = read(fd, buf, 1);
	if (*ret == 1 && (ft_strequ(buf, "\n")))
		return (1);
	else if (*ret == 1 && !(ft_strequ(buf, "\n")))
		fillit_print_error(-1);
	else
		return (0);
	return (0);
}

/*
** Verify the teramino and after it's valid it storages the tetramino
*/

t_list			*verify_file(int fd, t_board *mapa)
{
	char	*buf;
	int		ret;
	int		count;
	t_list	*pieces;

	ret = 0;
	pieces = NULL;
	count = 0;
	buf = ft_strnew(20);
	while ((ret = read(fd, buf, 20)) > 0 && ++count)
	{
		if (verify_piece(buf) == TRUE && ret == 20 \
			&& (verify_valid_tetraminos(buf)) == TRUE && count < 27)
		{
			make_piece(&pieces, buf, count);
			mapa->valid = val_nl(buf, fd, &ret);
		}
		else
			fillit_print_error(READ_ERROR);
	}
	mapa->size = count;
	return (pieces);
}

/*
** The real main function, first we verify if the file is valid
** and at the same time we are verifying we are storing our
** tetraminos.
** then we execute the solver, that init the coordinates of
** tetraminos to 0 and then initiate the backtracking
*/

void			fillit_run(char *arg)
{
	t_list		*fillit;
	t_board		*mapa;
	int			fd;

	mapa = ft_memalloc(sizeof(t_board));
	if ((fd = open(arg, O_RDONLY)) < 0)
		fillit_print_error(OPEN_ERROR);
	fillit = verify_file(fd, mapa);
	close(fd);
	mapa = solver(fillit, mapa);
	print_board_dyn(mapa->board, mapa->size);
	return ;
}
