/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regien <gmalpart@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 20:48:56 by regien            #+#    #+#             */
/*   Updated: 2017/10/21 06:58:46 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*top;
	t_list	*iteri;

	if (!lst)
		return (NULL);
	if (!(iteri = ft_lstnew(NULL, 0)))
		return (NULL);
	iteri = f(lst);
	top = iteri;
	while (lst->next)
	{
		lst = lst->next;
		iteri->next = f(lst);
		iteri = iteri->next;
	}
	return (top);
}
