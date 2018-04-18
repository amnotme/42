/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 05:09:44 by asarandi          #+#    #+#             */
/*   Updated: 2018/04/06 05:10:42 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft.h"

char	**create_char_array_copy(char **src, int extra)
{
	char	**dst;
	int		count;
	int		i;

	count = count_char_array(src);
	dst = ft_memalloc((count + 1 + extra) * sizeof(char *));
	i = 0;
	while (i < count)
	{
		dst[i] = ft_strdup(src[i]);
		i++;
	}
	while (i < count + 1 + extra)
		dst[i++] = NULL;
	return (dst);
}

void	destroy_char_array(char **array)
{
	int	count;
	int	i;

	count = count_char_array(array);
	i = 0;
	while (i < count)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return ;
}

int		count_char_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		i++;
	return (i);
}

char	**add_element_to_char_array(char **array, char *string)
{
	char	**new_array;
	int		count;

	new_array = create_char_array_copy(array, 1);
	count = count_char_array(new_array);
	new_array[count] = string;
	return (new_array);
}
