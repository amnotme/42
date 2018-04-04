/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 11:51:15 by asarandi          #+#    #+#             */
/*   Updated: 2017/09/25 13:51:55 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list	*elem))
{
	t_list	*p;

	while (lst->next != NULL)
	{
		p = lst->next;
		f(lst);
		lst = p;
	}
	f(lst);
}
