/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 23:15:58 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/03/22 19:07:16 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

t_queue			*queue_new(char *name)
{
	t_queue	*node;

	if (!name)
		return (NULL);
	if (!(node = (t_queue *)ft_memalloc(sizeof(t_queue))))
		return (NULL);
	if (!(node->name = (char *)ft_memalloc(ft_strlen(name) + 1)))
		return (NULL);
	ft_strcpy(node->name, (const char*)name);
	node->next = NULL;
	return (node);
}

t_queue			*queue_enqueue(t_queue *head, t_queue *node)
{
	t_queue *cursor;

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

t_queue			*queue_dequeue(t_queue *head)
{
	t_queue	*cpy;

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

int				queue_len(t_queue *head)
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
