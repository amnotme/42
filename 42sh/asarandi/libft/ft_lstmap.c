/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 11:51:58 by asarandi          #+#    #+#             */
/*   Updated: 2017/09/25 15:29:07 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*start;
	t_list	*new;
	t_list	*prev;

	if ((start = malloc(sizeof(t_list))) == NULL)
		return (NULL);
	start = f(lst);
	start->next = NULL;
	lst = lst->next;
	prev = start;
	while (lst)
	{
		if ((new = malloc(sizeof(t_list))) == NULL)
			return (NULL);
		new = f(lst);
		if (start->next == NULL)
			start->next = new;
		if (prev->next == NULL)
			prev->next = new;
		prev = new;
		new->next = NULL;
		lst = lst->next;
	}
	return (start);
}
