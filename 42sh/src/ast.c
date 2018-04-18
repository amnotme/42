/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 14:06:49 by asarandi          #+#    #+#             */
/*   Updated: 2018/04/15 14:06:59 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parse.h"

t_ast			*ast_new(char *name, t_type type)
{
	t_ast	*node;

	if (!name)
		return (NULL);
	if (!(node = (t_ast *)ft_memalloc(sizeof(t_ast))))
		return (NULL);
	if (!(node->name = (char *)ft_memalloc(ft_strlen(name) + 1)))
		return (NULL);
	ft_strcpy(node->name, (const char*)name);
	node->type = type;
	node->next = NULL;
	node->parent = NULL;
	node->right = NULL;
	return (node);
}

t_ast			*ast_enqueue(t_ast *head, t_ast *node)
{
	t_ast *cursor;

	if (!node)
		return (head);
	if (!head)
		return (node);
	cursor = head;
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = node;
	return (head);
}

t_ast			*ast_dequeue(t_ast *head)
{
	t_ast	*cpy;

	if (!head)
		return (NULL);
	if (!head->next)
	{
		ft_strdel(&head->name);
		ft_memdel((void **)&head);
		return (NULL);
	}
	cpy = head;
	while (head->next->next)
		head = head->next;
	ft_strdel(&head->next->name);
	ft_memdel((void **)head->next);
	return (cpy);
}

int				ast_len(t_ast *head)
{
	int		i;

	i = 0;
	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}
