/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_columns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 16:03:23 by asarandi          #+#    #+#             */
/*   Updated: 2018/04/08 18:22:15 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft.h"

int		col_print_cmd(char *s, int j, int cw, int nc)
{
	int	k;

	ft_printf(STDOUT_FILENO, "%s", s);
	k = ft_strlen(s);
	if (j < nc - 1)
	{
		while (k++ < cw)
			ft_printf(STDOUT_FILENO, " ");
		return (1);
	}
	else
	{
		ft_printf(STDOUT_FILENO, "\n");
		return (0);
	}
	return (1);
}

void	col_if_flag_print_newline(int *f)
{
	if (*f == 1)
	{
		ft_printf(STDOUT_FILENO, "\n");
		(*f) = 0;
	}
}

void	col_print_loop(int cw, int nc, int count, t_exec **a)
{
	int	i;
	int j;
	int f;
	int nr;

	nr = 0;
	while (nr * nc < count)
		nr++;
	i = 0;
	while (i < nr)
	{
		j = 0;
		while (j < nc)
		{
			if (i + j * nr < count)
				f = col_print_cmd(basename(a[i + j * nr]->cmd), j, cw, nc);
			else
				col_if_flag_print_newline(&f);
			j++;
		}
		i++;
	}
	if (f)
		ft_printf(STDOUT_FILENO, "\n");
}

void	tab_print_columns(t_exec **array, int count)
{
	int				max_len;
	int				cw;
	struct winsize	ws;
	int				nc;

	ft_printf(STDOUT_FILENO, "\n");
	max_len = tab_max_length(array);
	if (ioctl(0, TIOCGWINSZ, &ws) == -1)
		return ;
	cw = max_len + 2;
	nc = ws.ws_col / cw;
	col_print_loop(cw, nc, count, array);
}
