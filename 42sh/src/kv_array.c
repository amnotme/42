/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kv_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 05:11:00 by asarandi          #+#    #+#             */
/*   Updated: 2018/04/06 06:58:00 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft.h"

int		kv_array_get_key_index(char **array, char *key)
{
	int	count;
	int klen;
	int i;

	count = count_char_array(array);
	klen = ft_strlen(key);
	i = 0;
	while (i < count)
	{
		if (ft_strncmp(array[i], key, klen) == 0)
		{
			if (array[i][klen] == '=')
				return (i);
		}
		i++;
	}
	return (-1);
}

char	*kv_array_get_key_value(char **array, char *key)
{
	int		index;
	char	*value;

	index = kv_array_get_key_index(array, key);
	if (index == -1)
		return (NULL);
	value = ft_strchr(array[index], '=');
	if (value == NULL)
		return (NULL);
	return (value + 1);
}

char	*create_kv_string(char *key, char *value)
{
	char	*result;
	int		k_len;
	int		v_len;

	k_len = ft_strlen(key);
	v_len = ft_strlen(value);
	result = ft_memalloc(k_len + v_len + 2);
	ft_strncpy(result, key, k_len);
	result[k_len] = '=';
	ft_strncpy(&result[k_len + 1], value, v_len);
	return (result);
}

void	kv_array_set_key_value(char ***array, char *key, char *value)
{
	int		index;
	char	**new_array;
	char	*new_element;

	index = kv_array_get_key_index((*array), key);
	new_element = create_kv_string(key, value);
	if (index == -1)
	{
		new_array = add_element_to_char_array((*array), new_element);
		destroy_char_array((*array));
		*array = new_array;
		return ;
	}
	else
	{
		free((*array)[index]);
		(*array)[index] = new_element;
	}
	return ;
}

void	kv_array_remove_key(char **array, char *key)
{
	int	index;
	int i;

	index = kv_array_get_key_index(array, key);
	if (index == -1)
		return ;
	free(array[index]);
	i = index + 1;
	while (array[i] != NULL)
	{
		array[index++] = array[i++];
	}
	array[index] = NULL;
	return ;
}
