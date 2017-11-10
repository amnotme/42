/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 21:38:06 by lhernand          #+#    #+#             */
/*   Updated: 2017/11/09 17:32:01 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Iterates the list lst and applies the function f to each link.
*/

void		ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	while (lst)
	{
		f(lst);
		lst = lst->next;
	}
}
