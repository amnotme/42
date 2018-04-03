/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 03:44:11 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/04 23:56:03 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get.h"

int		ft_get_dir_len(char *str)
{
	int				i;
	DIR				*dir;
	struct dirent	*rep;

	i = 0;
	if (!(dir = opendir(str)))
		return (i);
	while (!(rep = readdir(dir)))
		i++;
	closedir(dir);
	return (i);
}

void	ft_get_op(t_op *op, char *argv)
{
	argv++;
	while (argv && *argv)
	{
		if (!OP(*argv))
		{
			ft_printf("ls: illegal option -- %c\n", *argv);
			ft_printf(USAGE);
			ft_printf("\n");
			exit(1);
		}
		if (*argv == 'l')
			op->l = *argv++;
		if (*argv == 'R')
			op->z = *argv++;
		if (*argv == 'a')
			op->a = *argv++;
		if (*argv == 'r')
			op->r = *argv++;
		if (*argv == 't')
			op->t = *argv++;
	}
}

int		ft_get_nbr(int n)
{
	int	i;

	i = n ? 0 : 1;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int		ft_get_size(t_liste *head)
{
	return (ft_get_nbr((int)major(head->sbuf->st_rdev))
			+ 2 + ft_get_nbr((int)minor(head->sbuf->st_rdev)));
}

void	ft_get_len(t_liste *head, t_len *len)
{
	int	nlink;
	int	nown;
	int	ngrp;
	int	size;
	int	m;

	while (head)
	{
		nlink = ft_get_nbr((int)head->sbuf->st_nlink);
		nown = ft_strlen(getpwuid(head->sbuf->st_uid)->pw_name);
		ngrp = ft_strlen(getgrgid(head->sbuf->st_gid)->gr_name);
		if (ft_format_type(head) == 'd' || ft_format_type(head) == 'c')
			size = ft_get_size(head);
		else
			size = ft_get_nbr(head->sbuf->st_size);
		len->link = nlink > len->link ? nlink : len->link;
		len->own = nown > len->own ? nown : len->own;
		len->grp = ngrp > len->grp ? ngrp : len->grp;
		len->size = size > len->size ? size : len->size;
		m = ft_get_nbr(major(head->sbuf->st_rdev));
		len->maj = m > len->maj ? m : len->maj;
		m = ft_get_nbr(minor(head->sbuf->st_rdev));
		len->min = m > len->min ? m : len->min;
		head = head->next;
	}
}
