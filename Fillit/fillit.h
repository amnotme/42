/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regien <gmalpart@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 08:00:46 by regien            #+#    #+#             */
/*   Updated: 2017/11/30 20:32:49 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "./libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

/*
** Error Codes.
*/

# define TRUE 			(1)
# define FALSE 			(0)
# define OPEN_ERROR 	(-1)
# define MALLOC_ERROR 	(-2)
# define READ_ERROR 	(-3)
# define COUNT_ERROR 	(-4)
# define FORMAT_ERROR	(-5)
# define BUFF_SIZE		(558)

/*
** Global Variables
*/

extern int g_o[3][19];

typedef struct		s_piece
{
	char			**piece;
	int				*x;
	int				*y;
	char			letra;
}					t_piece;

typedef struct		s_board
{
	char			**board;
	int				size;
	int				valid;
}					t_board;

/*
**	functions to handle errors
**	step0_errors.c
*/

void				fillit_print_usage(char *arg);
void				fillit_print_error(int error_code);

/*
**	functions to validate file, piece, and tetraminos.
**	step1_validations.c
*/

int					verify_piece(char *data);
int					val_nl(char *buf, int fd, int *ret);
int					verify_valid_tetraminos(char *data);
void				fillit_run(char *arg);
t_list				*verify_file(int fd, t_board *mapa);

/*
**	functions to prepare a map, to verify it, generate it, and print it
**	step2_board_setup.c
*/

int					verify_map(char **board, int size);
char				**gen_board(int size);
void				full_dots(char **board);
void				full_dots_dyn(char **board, int size);
void				print_board_dyn(char **board, int size);

/*
**	functions to create list and stores elements inside it.
**	step3_storage_and_coordinate_reset.c
*/

char				**mod_str(char **str, t_piece *dummy);
char				**init_cero(char **str, t_piece *dummy);
char				**get_coord(char **str, t_piece *dummy);
void				make_piece(t_list **pieces, char *buf, int count);
t_list				*create_element(char *str, int contador);

/*
**	functions that implement the backtrack recursion.
**	step4_backtracking.c
*/

int					backtrack(t_board *board, t_list *pieces);
int					check_valid_position(t_board *mapa, t_list *piezas, \
					int x, int y);
char				**put_piece(char **mapa, t_list *piezas, int x, int y);
char				**remove_piece(char **mapa, t_list *piezas, int x, int y);
t_board				*solver(t_list *pieces, t_board *mapa);

#endif
