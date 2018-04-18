/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 14:07:54 by asarandi          #+#    #+#             */
/*   Updated: 2018/04/15 14:17:18 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parse.h"

void	print_ast(t_ast *node)
{
	while (node)
	{
		ft_putstr("[");
		ft_putstr(node->name);
		ft_putstr("]");
		if (node->right)
		{
			ft_putstr("\t->\t[");
			ft_putstr(node->right->name);
			ft_putstr("]");
			ft_putstr("[");
			ft_putnbr(node->right->type);
			ft_putstr("]");
		}
		ft_putstr("\n");
		node = node->next;
	}
}

void	print_trees(t_ast **ast)
{
	int i;

	i = 0;
	while (ast && *ast)
	{
		ft_putstr("***** TREE [");
		ft_putnbr(i++);
		ft_putstr("] *****\n");
		print_ast(*ast);
		ft_putstr("***** END *****\n\n");
		ast++;
	}
}

void	print_error_lexer(void)
{
	ft_putstr("Parse error lexer [CMD invalid]\n");
}

void	print_error_ast(void)
{
	ft_putstr("Parse error ast\n");
}
