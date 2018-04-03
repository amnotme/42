/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 02:40:06 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/02/11 19:05:20 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_len	*ft_initialize_len(void)
{
	t_len	*len;

	if (!(len = ft_memalloc(sizeof(t_len))))
		exit(1);
	if (len)
	{
		len->link = 0;
		len->own = 0;
		len->grp = 0;
		len->size = 0;
		len->maj = 0;
		len->min = 0;
		len->blocks = 0;
	}
	return (len);
}

void	ft_parse_dir(t_liste *head, t_op *op, char *parent)
{
	char	*path;

	while (head)
	{
		if (IS_IFDIR(head->sbuf->st_mode)
				&& ft_strcmp(head->rep->d_name, ".")
				&& ft_strcmp(head->rep->d_name, ".."))
		{
			if (IS_DOT(op, head))
			{
				path = ft_concat_path(parent, head->rep->d_name);
				ft_printf("\n%s:\n", path);
				ft_parse_args(op, path);
				ft_strdel(&path);
			}
		}
		head = head->next;
	}
}

void	ft_parse_liste(t_liste *head, t_op *op, t_len *len, char *str)
{
	while (head)
	{
		if (IS_DOT(op, head))
			ft_print(head, op, len, str);
		head = head->next;
	}
}

void	ft_parse_args(t_op *op, char *str)
{
	t_liste			*head;
	DIR				*dir;
	struct dirent	*rep;
	struct stat		sbuf;
	struct s_len	*len;

	head = NULL;
	len = ft_initialize_len();
	if (!ft_opendir(&dir, str))
		return ;
	while ((rep = readdir(dir)))
	{
		if (!ft_lstat(str, ft_concat_path(str, rep->d_name), &sbuf))
			return ;
		head = ft_liste_add(head, ft_liste_new(rep, &sbuf), len, op);
	}
	ft_get_len(head, len);
	head = ft_sort(head, op);
	if (op->l)
		ft_printf("total %d\n", len->blocks);
	ft_parse_liste(head, op, len, str);
	if (op->z)
		ft_parse_dir(head, op, str);
	ft_liste_clear(head, &len);
	(void)closedir(dir);
}
