/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <gmalpart@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 07:37:07 by gmalpart          #+#    #+#             */
/*   Updated: 2017/10/21 07:37:09 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*opt;

	opt = NULL;
	if (size)
	{
		if (!(opt = malloc(sizeof(unsigned char) * size)))
			return (NULL);
		while (size)
		{
			opt[--size] = 0;
		}
	}
	return ((void*)opt);
}
