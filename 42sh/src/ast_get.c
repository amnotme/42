/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 14:07:15 by asarandi          #+#    #+#             */
/*   Updated: 2018/04/15 14:29:51 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parse.h"

t_type	get_type(char *str)
{
	if (IS_RED_NEXT(str))
		return (RED_NEXT);
	if (IS_RED_NNEXT(str))
		return (RED_NNEXT);
	if (IS_RED_PREV(str))
		return (RED_PREV);
	if (IS_RED_PIPE(str))
		return (RED_PIPE);
	if (IS_OP_AND(str))
		return (OP_AND);
	if (IS_OP_OR(str))
		return (OP_OR);
	if (IS_SEP(str))
		return (SEP);
	return (CMD);
}

char	*get_type_string(char *str)
{
	char *dest;

	if (ft_strlen(str) >= 2 &&
			(dest = ft_strcpy_alloc(str, 2)) && IS_TERM(dest))
		return (dest);
	if (ft_strlen(str) && (dest = ft_strcpy_alloc(str, 1)) && IS_TERM(dest))
		return (dest);
	return (NULL);
}

int		get_nbr_instructions(t_ast *lex)
{
	int i;

	if (!lex)
		return (0);
	i = 1;
	while (lex)
	{
		if (lex->type == SEP)
			i++;
		else if (lex->type == CMD)
			i += get_nbr_redirection(lex->name);
		lex = lex->next;
	}
	return (i);
}

int		get_nbr_redirection(char *str)
{
	int i;

	i = 0;
	while (str && *str)
	{
		if (*str == '>' || *str == '<')
			i++;
		str++;
	}
	return (i);
}
