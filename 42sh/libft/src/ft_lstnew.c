/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 11:48:24 by asarandi          #+#    #+#             */
/*   Updated: 2017/09/25 12:40:20 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list			*lst;
	unsigned char	*cnt;

	if ((lst = malloc(sizeof(t_list))) == NULL)
		return (NULL);
	lst->next = NULL;
	if (!content)
	{
		lst->content = NULL;
		lst->content_size = 0;
		return (lst);
	}
	if ((cnt = (unsigned char *)malloc(content_size)) == NULL)
	{
		free(lst);
		return (NULL);
	}
	ft_memcpy(cnt, content, content_size);
	lst->content = cnt;
	lst->content_size = content_size;
	return (lst);
}
