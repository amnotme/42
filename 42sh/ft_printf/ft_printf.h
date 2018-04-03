/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 19:43:25 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/04 23:46:11 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_struct.h"
# include "ft_get.h"
# include "ft_set1.h"
# include "ft_set2.h"
# include "ft_helper.h"
# include "ft_find.h"
# include "ft_printf_header.h"

char				*ft_format(char *str, va_list *args);

typedef struct		s_get
{
	int				(*f)(char *, t_cs *);
}					t_get;

typedef struct		s_set
{
	char			type;
	char			*(*f)(va_list *, t_cs *);
}					t_set;

const t_set			g_sets[] =
{
	{ 's', ft_set_s },
	{ 'S', ft_set_s },
	{ 'p', ft_set_p },
	{ 'd', ft_set_d },
	{ 'D', ft_set_d },
	{ 'i', ft_set_d },
	{ 'o', ft_set_o },
	{ 'O', ft_set_o },
	{ 'u', ft_set_u },
	{ 'U', ft_set_u },
	{ 'x', ft_set_x },
	{ 'X', ft_set_x },
	{ 'c', ft_set_c },
	{ 'C', ft_set_c },
	{ '%', ft_set_z }
};

const t_get			g_gets[] =
{
	{ ft_get_type },
	{ ft_get_mod },
	{ ft_get_width },
	{ ft_get_prec },
	{ ft_get_flags }
};

#endif
