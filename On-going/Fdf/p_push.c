/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_push.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 17:20:46 by lhernand          #+#    #+#             */
/*   Updated: 2017/12/19 18:36:33 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p.h"

void				push(t_list **list, void *node, int x, int y)
{
	t_list *lst;

	if (*list)
	{
		lst = *list;
		while (lst->next)
			lst = lst->next;
		printf("before \n");
		lst->next = create(node, x, y);
		printf("after \n");
	}
	else
		*list = create(node, x, y);
}
