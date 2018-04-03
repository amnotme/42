/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 19:53:40 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/03 22:59:56 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

char	*ft_format_year(char *str)
{
	char	*out;

	if (!str || !(out = ft_memalloc(5)))
		return (NULL);
	out[0] = str[21];
	out[1] = str[22];
	out[2] = str[23];
	out[3] = str[24];
	out[4] = '\0';
	return (out);
}

char	*ft_format_time(char *str)
{
	char	*out;

	if (!str || !(out = ft_memalloc(13)))
		return (NULL);
	out[0] = str[4];
	out[1] = str[5];
	out[2] = str[6];
	out[3] = ' ';
	out[4] = str[8];
	out[5] = str[9];
	out[6] = ' ';
	out[7] = str[11];
	out[8] = str[12];
	out[9] = str[13];
	out[10] = str[14];
	out[11] = str[15];
	out[12] = '\0';
	return (out);
}

char	ft_format_type(t_liste *node)
{
	if (IS_IFIFO(node->sbuf->st_mode))
		return ('p');
	else if (IS_IFCHR(node->sbuf->st_mode))
		return ('c');
	else if (IS_IFBLK(node->sbuf->st_mode))
		return ('b');
	else if (IS_IFREG(node->sbuf->st_mode))
		return ('-');
	else if (IS_IFLINK(node->sbuf->st_mode))
		return ('l');
	else if (IS_IFSOCK(node->sbuf->st_mode))
		return ('s');
	else if (IS_IFDIR(node->sbuf->st_mode))
		return ('d');
	return ('x');
}

char	*ft_format_chmod(mode_t mode)
{
	char		*out;
	size_t		i;
	const char	chars[] = "rwxrwxrwx";

	if (!(out = ft_memalloc(10)))
		return (NULL);
	i = -1;
	out[0] = 'r';
	out[1] = 'w';
	out[2] = 'x';
	out[3] = 'r';
	out[4] = 'w';
	out[5] = 'x';
	out[6] = 'r';
	out[7] = 'w';
	out[8] = 'x';
	while (++i < 9)
		out[i] = (mode & (1 << (8 - i))) ? chars[i] : '-';
	out[9] = '\0';
	return (out);
}

char	*ft_concat_path(char *parent, char *str)
{
	char	*out;

	if (!(out = ft_memalloc(ft_strlen(parent) + ft_strlen(str) + 3)))
		exit(1);
	out = ft_strcpy(out, parent);
	out = ft_strcat(out, "/");
	out = ft_strcat(out, str);
	return (out);
}
