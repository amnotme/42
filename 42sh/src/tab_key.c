/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 05:25:17 by asarandi          #+#    #+#             */
/*   Updated: 2018/04/15 19:38:56 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft.h"

t_exec	**tab_array_of_matches(t_shell *sh)
{
	t_exec	**result;
	t_exec	*ptr;
	int		count;
	int		i;
	int		needle_len;

	count = tab_count_matches(sh);
	result = ft_memalloc((count + 1) * sizeof(t_exec *));
	i = 0;
	ptr = sh->exec;
	needle_len = ft_strlen(sh->buffer);
	while (i < count)
	{
		if (ft_strncmp(sh->buffer, basename(ptr->cmd), needle_len) == 0)
			result[i++] = ptr;
		ptr = ptr->next;
	}
	result[i] = NULL;
	return (result);
}

void	tab_remove_duplicates(t_exec **array, int *count)
{
	int		i;
	int		k;
	char	*a;
	char	*b;

	i = 0;
	while (i < *count - 1)
	{
		a = basename(array[i]->cmd);
		b = basename(array[i + 1]->cmd);
		if (ft_strcmp(a, b) == 0)
		{
			k = i + 1;
			while (k < *count)
			{
				array[k] = array[k + 1];
				k++;
			}
			array[k] = NULL;
			(*count)--;
			continue;
		}
		i++;
	}
}

int		tab_mini_complete(t_shell *sh, t_exec **a)
{
	char	c;
	int		i_len;

	if (tab_all_commands_longer(sh, a) == 1)
	{
		i_len = sh->input_size;
		c = basename(a[0]->cmd)[i_len];
		if (tab_all_commands_share_letter(a, i_len, c) == 1)
		{
			sh->buffer[i_len] = c;
			sh->input_size++;
			sh->buf_i++;
			reprint_input(sh);
			return (1 + tab_mini_complete(sh, a));
		}
	}
	return (0);
}

void	key_tab_function(t_shell *sh)
{
	t_exec	**matches;
	int		i;

	if ((sh->input_size > 0) && (string_has_whitespace(sh->buffer) == 0))
	{
		matches = tab_array_of_matches(sh);
		i = tab_count_matches(sh);
		tab_bubble_sort(matches, i);
		tab_remove_duplicates(matches, &i);
		if (i == 1)
		{
			sh->buf_i = ft_strlen(basename(matches[0]->cmd));
			sh->buffer[sh->buf_i++] = ' ';
			sh->input_size = sh->buf_i;
		}
		else if ((i > 1) && (tab_mini_complete(sh, matches) == 0))
		{
			tab_print_columns(matches, i);
		}
		free(matches);
		reprint_input(sh);
	}
	return ;
}
