/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 14:07:05 by asarandi          #+#    #+#             */
/*   Updated: 2018/04/15 23:23:48 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parse.h"

void	free_ast(t_ast *head)
{
	head->name = NULL;
}

void	free_trees(t_ast **ast)
{
	while (ast && *ast)
	{
		free_ast(*ast);
		ast++;
	}
}

size_t	free_parse_ast(char **term)
{
	size_t i;

	i = ft_strlen(*term);
	ft_strdel(term);
	*term = NULL;
	return (i);
}
