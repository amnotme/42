/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 16:00:36 by asarandi          #+#    #+#             */
/*   Updated: 2018/04/08 16:02:04 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft.h"

int		tab_count_matches(t_shell *sh)
{
	int		count;
	int		needle_len;
	t_exec	*ptr;

	if ((needle_len = ft_strlen(sh->buffer)) < 1)
		return (0);
	ptr = sh->exec;
	count = 0;
	while (ptr != NULL)
	{
		if (ft_strncmp(sh->buffer, basename(ptr->cmd), needle_len) == 0)
			count += 1;
		ptr = ptr->next;
	}
	return (count);
}

int		tab_all_commands_longer(t_shell *sh, t_exec **a)
{
	size_t	k_len;
	int		i;

	i = 0;
	while (a[i] != NULL)
	{
		k_len = ft_strlen(basename(a[i]->cmd));
		if (k_len <= sh->input_size)
			return (0);
		i++;
	}
	return (1);
}

int		tab_all_commands_share_letter(t_exec **a, int index, char c)
{
	int		i;
	char	*cmd;

	i = 0;
	while (a[i] != NULL)
	{
		cmd = basename(a[i]->cmd);
		if (cmd[index] != c)
			return (0);
		i++;
	}
	return (1);
}

int		tab_max_length(t_exec **array)
{
	int		i;
	int		len;
	int		max_length;

	i = 0;
	max_length = 0;
	while (array[i] != NULL)
	{
		len = ft_strlen(basename(array[i]->cmd));
		if (len > max_length)
			max_length = len;
		i++;
	}
	return (max_length);
}

void	tab_bubble_sort(t_exec **a, int count)
{
	int		i;
	int		flag;
	t_exec	*tmp;

	while (1)
	{
		i = 0;
		flag = 0;
		while (i < count - 1)
		{
			if (ft_strcmp(basename(a[i]->cmd), basename(a[i + 1]->cmd)) > 0)
			{
				flag = 1;
				tmp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = tmp;
			}
			i++;
		}
		if (flag == 0)
			break ;
	}
}
