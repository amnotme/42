/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:07:03 by lhernand          #+#    #+#             */
/*   Updated: 2017/11/30 18:42:08 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Add a new element to the end of the list;
*/

void			ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list		*iter;

	if (!new || !alst)
		return ;
	iter = *alst;
	while (iter->next != NULL)
		iter = iter->next;
	iter->next = new;
}
