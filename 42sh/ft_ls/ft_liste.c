/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_liste.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 03:46:44 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/02/11 19:29:42 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_liste.h"

t_liste		*ft_liste_new(struct dirent *rep, struct stat *sbuf)
{
	t_liste	*node;

	if (!(node = (t_liste *)ft_memalloc(sizeof(t_liste))))
		exit(1);
	if (!(node->rep = (struct dirent *)ft_memalloc(sizeof(struct dirent))))
		exit(1);
	if (!(node->sbuf = (struct stat *)ft_memalloc(sizeof(struct stat))))
		exit(1);
	node->rep = (struct dirent *)ft_memcpy((struct dirent *)node->rep,
			(struct dirent *)rep, sizeof(*rep));
	node->sbuf = (struct stat *)ft_memcpy((struct stat *)node->sbuf,
			(struct stat *)sbuf, sizeof(*sbuf));
	node->next = NULL;
	return (node);
}

t_liste		*ft_liste_add(t_liste *head,
		t_liste *node, struct s_len *len, t_op *op)
{
	t_liste	*current;

	current = head;
	if (IS_DOT(op, node))
		len->blocks += node->sbuf->st_blocks;
	if (!current)
		return (node);
	while (current->next)
		current = current->next;
	current->next = node;
	return (head);
}

void		ft_liste_clear(t_liste *head, t_len **len)
{
	t_liste	*next;

	next = NULL;
	ft_memdel((void **)len);
	if (!head)
		return ;
	while (head)
	{
		next = head->next;
		ft_memdel((void **)&head->rep);
		ft_memdel((void **)&head->sbuf);
		ft_memdel((void **)&head);
		head = next;
	}
}
