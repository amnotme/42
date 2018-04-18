/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 00:05:19 by passef            #+#    #+#             */
/*   Updated: 2018/04/18 01:48:38 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# define IS_RED_NEXT(x) (!ft_strcmp_withspace(x, ">"))
# define IS_RED_NNEXT(x) (!ft_strcmp_withspace(x, ">>"))
# define IS_RED_PREV(x) (!ft_strcmp_withspace(x, "<"))
# define IS_RED_PIPE(x) (!ft_strcmp_withspace(x, "|"))
# define IS_RED1(x) (IS_RED_NEXT(x) || IS_RED_NNEXT(x) || IS_RED_PREV(x))
# define IS_RED(x) (IS_RED1(x) || IS_RED_PIPE(x))
# define IS_OP_AND(x) (!ft_strcmp_withspace(x, "&&"))
# define IS_OP_OR(x) (!ft_strcmp_withspace(x, "||"))
# define IS_OP(x) (IS_OP_AND(x) || IS_OP_OR(x))
# define IS_SEP(x) (!ft_strcmp_withspace(x, ";"))
# define IS_TERM(x) (IS_OP(x) || IS_SEP(x) || IS_RED(x))
# include "../libft/inc/libft.h"
# include "../libft/inc/libftprintf.h"
# include <stdio.h>

typedef enum		e_type
{
	CMD,
	FILES,
	RED_NEXT,
	RED_NNEXT,
	RED_PREV,
	RED_PIPE,
	OP_AND,
	OP_OR,
	SEP,
	ROOT,
	NUL
}					t_type;

typedef struct		s_ast
{
	char			*name;
	t_type			type;
	struct s_ast	*parent;
	struct s_ast	*next;
	struct s_ast	*right;
}					t_ast;

/*
** free.c
*/

void				free_ast(t_ast *head);
void				free_trees(t_ast **ast);
size_t				free_parse_ast(char **term);

/*
** get.c
*/

t_type				get_type(char *str);
int					get_nbr_instructions(t_ast *lex);
int					get_nbr_redirection(char *str);
char				*get_type_string(char *str);

/*
** helper.c
*/

char				*remove_start_space(char *str);
char				*delete_backslash_in_double_quote(char *str);
int					set_backslash(char *dest, char *str, int i);

/*
** ast_parse.c
*/

t_ast				*parse_lexer(char *str);
t_ast				*cpy_ast(char *word, t_ast *lex, t_ast *node);
t_ast				**parse_ast(t_ast **ast, t_ast *lex);
t_ast				*parse_tree(t_ast *lex);
t_ast				*parse_tree_set_redirect(t_ast *ast);

/*
** parse_quote.c
*/
int					parse_quote(char **word, char *str);
int					parse_quote_single(char **word, char *str);
int					parse_quote_double(char **word, char *str);
int					copy_str(int i, int res, char **word, char *cpy);

/*
** print.c
*/

void				print_ast(t_ast *node);
void				print_trees(t_ast **ast);
void				print_lexer_start_error(char *name);
void				print_error_lexer(void);
void				print_error_ast(void);

/*
** ast.c
*/

t_ast				*ast_new(char *name, t_type type);
t_ast				*ast_enqueue(t_ast *head, t_ast *node);
t_ast				*ast_dequeue(t_ast *head);
t_ast				*ast_deast_front(t_ast *head);
int					ast_len(t_ast *head);

/*
** validate.c
*/

t_ast				*validate_lexer(t_ast *lex);
t_ast				*validate_ast(t_ast *ast);

/*
** ast_util.c
*/

t_ast				**ast_create_tree(char *str);
int					ast_ambiguous_error(char *msg);
int					ast_is_ambiguous(t_ast *ast);
void				init_parse_lexer(t_ast **lex, t_ast **node,
					char **word, char **term);
t_ast				*parse_help1(t_ast **lex, t_ast **node,
					char **word, char **term);

#endif
