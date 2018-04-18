/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 14:07:46 by asarandi          #+#    #+#             */
/*   Updated: 2018/04/18 01:14:39 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parse.h"

t_ast	*parse_lexer(char *str)
{
	t_ast	*lex;
	t_ast	*node;
	char	*word;
	char	*term;
	int		res;

	init_parse_lexer(&lex, &node, &word, &term);
	while (str && *str)
	{
		if (*str == '\'' || *str == '"')
		{
			if (!(res = parse_quote(&word, str)))
				return (NULL);
			str += res;
		}
		else if (*str && *str != ' ' && (term = get_type_string(str)))
		{
			if (!(parse_help1(&lex, &node, &word, &term)))
				return (NULL);
			str += free_parse_ast(&term);
		}
		else
			word = ft_str_append(word, *str++);
	}
	return (cpy_ast(word, lex, node));
}

t_ast	*cpy_ast(char *word, t_ast *lex, t_ast *node)
{
	if (ft_strlen(word))
	{
		node = ast_new(remove_start_space(word), CMD);
		if (node && !(lex = ast_enqueue(lex, node)))
			return (NULL);
		ft_strdel(&word);
		word = NULL;
	}
	return (validate_lexer(lex));
}

t_ast	**parse_ast(t_ast **ast, t_ast *lex)
{
	int		i;

	i = 0;
	ast[i] = NULL;
	while (lex)
	{
		if (lex->type == SEP)
			ast[++i] = NULL;
		else if (!(ast[i] = ast_enqueue(ast[i], ast_new(lex->name, lex->type))))
			return (NULL);
		lex = lex->next;
	}
	ast[++i] = 0;
	i = 0;
	while (ast[i])
	{
		if (!(ast[i] = parse_tree(ast[i])))
			return (NULL);
		i++;
	}
	return (ast);
}

t_ast	*parse_tree(t_ast *lex)
{
	t_ast	*ast;
	t_ast	*op;
	t_ast	*right;
	t_ast	*cpy;

	if (!lex || lex->type != CMD || !(ast = ast_new(lex->name, lex->type)))
		return (NULL);
	cpy = lex;
	lex = lex->next;
	while (lex)
	{
		if (lex->type == CMD || !(op = ast_new(lex->name, lex->type)))
			return (NULL);
		if (!(lex = lex->next) || lex->type != CMD ||
				!(right = ast_new(lex->name, lex->type)))
			return (NULL);
		op->next = ast;
		op->right = right;
		right->parent = op;
		ast->parent = op;
		ast = op;
		lex = lex->next;
	}
	free_ast(cpy);
	return (parse_tree_set_redirect(ast));
}

t_ast	*parse_tree_set_redirect(t_ast *ast)
{
	t_ast	*cpy;

	cpy = ast;
	while (ast)
	{
		if (ast->type == RED_NEXT || ast->type == RED_NNEXT ||
				ast->type == RED_PREV)
			ast->right->type = FILES;
		ast = ast->next;
	}
	return (validate_ast(cpy));
}
