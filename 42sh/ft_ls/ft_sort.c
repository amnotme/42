/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 18:15:06 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/03 08:03:31 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort.h"

t_liste		*ft_sort(t_liste *head, t_op *op)
{
	head = ft_sorting(head, ft_sort_lex);
	if (op->t)
		head = ft_sorting(head, ft_sort_time);
	if (op->r)
		head = ft_sort_rev(head);
	return (head);
}

t_liste		*ft_sorting(t_liste *head, int (*c)(t_liste *, t_liste *))
{
	t_liste			*current;
	t_liste			*suivant;
	struct dirent	*rep_tmp;
	struct stat		*sbuf_tmp;

	current = head;
	while (current && current->next)
	{
		suivant = current->next;
		while (suivant)
		{
			if (c(current, suivant))
			{
				rep_tmp = current->rep;
				sbuf_tmp = current->sbuf;
				current->rep = suivant->rep;
				current->sbuf = suivant->sbuf;
				suivant->rep = rep_tmp;
				suivant->sbuf = sbuf_tmp;
			}
			suivant = suivant->next;
		}
		current = current->next;
	}
	return (head);
}

t_liste		*ft_sort_rev(t_liste *head)
{
	t_liste	*back;
	t_liste	*current;
	t_liste	*suivant;

	back = NULL;
	suivant = head;
	while (suivant)
	{
		current = suivant;
		suivant = suivant->next;
		current->next = back;
		back = current;
	}
	return (current);
}

int			ft_sort_lex(t_liste *current, t_liste *suivant)
{
	if (!current || !suivant)
		return (0);
	return (ft_strcmp(current->rep->d_name, suivant->rep->d_name) > 0);
}

int			ft_sort_time(t_liste *current, t_liste *suivant)
{
	long	nsec1;
	long	nsec2;
	long	tsec1;
	long	tsec2;

	if (!current || !suivant)
		return (0);
	nsec1 = suivant->sbuf->st_mtimespec.tv_nsec;
	nsec2 = current->sbuf->st_mtimespec.tv_nsec;
	tsec1 = suivant->sbuf->st_mtimespec.tv_sec;
	tsec2 = current->sbuf->st_mtimespec.tv_sec;
	if (tsec1 != tsec2)
		return ((tsec1 > tsec2) ? 1 : 0);
	if (nsec1 != nsec2)
		return ((nsec1 > nsec2) ? 1 : 0);
	return (ft_sort_lex(current, suivant));
}
