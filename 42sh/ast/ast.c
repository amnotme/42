/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztisnes <ztisnes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 14:51:27 by ztisnes           #+#    #+#             */
/*   Updated: 2018/04/03 14:46:05 by ztisnes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <backend.h>
#include <error.h>

typedef struct		s_ast
{
	void			*data;
	struct s_btree	*left;
	struct s_btree	*right;
}					t_ast;

t_ast		*create_node(int *value)
{
	t_btree *root;

	root = malloc(sizeof(t_ast));
	root->data = value;
	root->left = NULL;
	root->right = NULL;
	return (root);
}

t_ast		*insert_left(t_btree *node, int *value)
{
	node->left = create_node(value);
	return (node->left);
}

t_ast		*insert_right(t_btree *node, int *value)
{
	node->right = create_node(value);
	return (node->right);
}
*/
