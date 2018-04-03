/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 03:30:33 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/02/12 00:10:37 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

void		ft_print_details(t_liste *node, t_len *len)
{
	struct passwd	*pwd;
	struct group	*grp;
	char			*chmod;
	char			*str;

	pwd = getpwuid(node->sbuf->st_uid);
	grp = getgrgid(node->sbuf->st_gid);
	chmod = ft_format_chmod(node->sbuf->st_mode);
	ft_printf("%c", ft_format_type(node));
	ft_printf("%s", chmod);
	str = ft_add_space_d(ft_itoa(node->sbuf->st_nlink), len->link);
	ft_printf(" %s", str);
	ft_strdel(&str);
	str = ft_add_space_s(pwd->pw_name, len->own);
	ft_printf(" %s", str);
	ft_strdel(&str);
	str = ft_add_space_s(grp->gr_name, len->grp);
	ft_printf("  %s", str);
	ft_strdel(&str);
	ft_strdel(&chmod);
}

void		ft_print_l(t_liste *node, t_len *len, char *tmp)
{
	char	*maj;
	char	*min;
	char	*size;

	ft_print_details(node, len);
	if (IS_IFCHR(node->sbuf->st_mode) || IS_IFBLK(node->sbuf->st_mode))
	{
		maj = ft_add_space_d(ft_itoa(major(node->sbuf->st_rdev)), len->maj);
		min = ft_add_space_d(ft_itoa(minor(node->sbuf->st_rdev)), len->min);
		ft_printf("  %s, %s", maj, min);
		ft_strdel(&maj);
		ft_strdel(&min);
	}
	else
	{
		size = ft_add_space_d(ft_itoa(node->sbuf->st_size), len->size);
		ft_printf("  %s ", size);
		ft_strdel(&size);
	}
	ft_printf(" %s ", tmp);
}

void		ft_print(t_liste *node, t_op *op, t_len *len, char *str)
{
	char	*tmp;
	char	*path;
	char	*buf;
	int		i;

	if (time(NULL) - node->sbuf->st_mtimespec.tv_sec > 15768000)
		tmp = ft_format_year(ctime(&node->sbuf->st_mtimespec.tv_sec));
	else
		tmp = ft_format_time(ctime(&node->sbuf->st_mtimespec.tv_sec));
	i = node->sbuf->st_size + 1;
	path = ft_concat_path(str, node->rep->d_name);
	if (!(buf = ft_memalloc(i)))
		exit(1);
	if (IS_IFLINK(node->sbuf->st_mode) && (readlink(path, buf, i) == -1))
		ft_strdel(&buf);
	if (op->l)
		ft_print_l(node, len, tmp);
	ft_printf("%s", node->rep->d_name);
	if (IS_IFLINK(node->sbuf->st_mode))
		ft_printf(" -> %s", buf);
	ft_printf("\n");
	ft_strdel(&tmp);
	ft_strdel(&path);
	ft_strdel(&buf);
}

int			ft_opendir(DIR **dir, char *str)
{
	if (!(*dir = opendir(str)))
	{
		ft_printf("ls: %s: %s\n", str, strerror(errno));
		return (0);
	}
	return (1);
}

int			ft_lstat(char *str, char *path, struct stat *sbuf)
{
	if (lstat(path, sbuf) == -1)
	{
		ft_printf("ls: %s: %s\n", str, strerror(errno));
		ft_strdel(&path);
		return (0);
	}
	ft_strdel(&path);
	return (1);
}
