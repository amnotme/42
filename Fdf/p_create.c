/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_create.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 17:19:42 by lhernand          #+#    #+#             */
/*   Updated: 2017/12/19 18:20:22 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p.h"

t_list			*create(void *data, int x, int y)
{
	t_list		*node;

	node = (t_list *)malloc(sizeof(t_list));
	node->data = data;
	node->x = x;
	node->y = y;
	node->next = NULL;
	return (node);
}
