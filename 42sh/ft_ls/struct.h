/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 03:45:47 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/04 23:56:43 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define OP(x) (x == 'l' || x == 'R' || x == 'a' || x == 'r' || x == 't')

# define IS_IFIFO(x) (((x) & S_IFMT) == S_IFIFO)
# define IS_IFCHR(x) (((x) & S_IFMT) == S_IFCHR)
# define IS_IFDIR(x) (((x) & S_IFMT) == S_IFDIR)
# define IS_IFBLK(x) (((x) & S_IFMT) == S_IFBLK)
# define IS_IFREG(x) (((x) & S_IFMT) == S_IFREG)
# define IS_IFLINK(x) (((x) & S_IFMT) == S_IFLNK)
# define IS_IFSOCK(x) (((x) & S_IFMT) == S_IFSOCK)
# define IS_IFWHT(x) (((x) & S_IFMT) == S_IFWHT)

# define IS_DOT(op, head) (op->a || (!op->a && *head->rep->d_name != '.'))

# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <errno.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <time.h>
# include <string.h>

# include "../ft_printf/ft_printf_header.h"

typedef struct		s_op
{
	char			l;
	char			z;
	char			a;
	char			r;
	char			t;
}					t_op;

typedef struct		s_len
{
	int				link;
	int				own;
	int				grp;
	int				size;
	int				maj;
	int				min;
	int				blocks;
}					t_len;

#endif
