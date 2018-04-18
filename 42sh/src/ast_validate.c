/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 14:08:01 by asarandi          #+#    #+#             */
/*   Updated: 2018/04/15 14:31:32 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parse.h"

t_ast	*validate_lexer(t_ast *lex)
{
	t_ast	*cpy;

	cpy = lex;
	while (lex)
	{
		if (!ft_strlen(lex->name) || lex->type != CMD)
			return (NULL);
		if ((lex = lex->next) && lex->type == CMD)
			return (NULL);
		lex = lex ? lex->next : lex;
	}
	return (cpy);
}

t_ast	*validate_ast(t_ast *ast)
{
	return (ast);
}
