/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regien <gmalpart@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 06:11:22 by regien            #+#    #+#             */
/*   Updated: 2017/10/13 20:16:26 by regien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*container;
	t_list		*remainder;

	container = *alst;
	while (container)
	{
		remainder = container->next;
		del((container->content), (container->content_size));
		free(container);
		container = remainder;
	}
	*alst = NULL;
}
