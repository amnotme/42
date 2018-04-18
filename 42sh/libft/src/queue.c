/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztisnes <ztisnes@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 17:59:27 by ztisnes           #+#    #+#             */
/*   Updated: 2018/04/15 20:11:16 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_queue				*init_queue(void)
{
	t_queue			*node;

	node = (t_queue *)ft_memalloc(sizeof(t_queue));
	node->first = NULL;
	node->last = NULL;
	return (node);
}

void				ft_enqueue(t_queue *queue, void *content)
{
	t_list			*node;

	node = (t_list *)ft_memalloc(sizeof(t_list));
	node->content = content;
	node->next = NULL;
	if (!queue->last)
	{
		queue->last = node;
		queue->first = node;
	}
	else
	{
		queue->last->next = node;
		queue->last = queue->last->next;
	}
	return ;
}

void				*ft_dequeue(t_queue *queue)
{
	t_list			*tmp;

	tmp = queue->first;
	if (tmp)
	{
		queue->first = tmp->next;
		return (tmp->content);
	}
	return (NULL);
}

void				*peek_queue(t_queue *queue)
{
	if (queue->first == NULL)
		return (NULL);
	return (queue->first->content);
}

int					is_empty(t_queue *queue)
{
	return (queue->first == NULL);
}
