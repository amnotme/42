/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 21:31:37 by lhernand          #+#    #+#             */
/*   Updated: 2017/11/09 17:31:31 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Adds the element new at the beginnning of the list.
*/

void		ft_lstadd(t_list **alst, t_list *new)
{
	t_list	*elem;

	elem = new;
	elem->next = *alst;
	*alst = elem;
}
