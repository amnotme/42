/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 23:21:37 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/05 01:16:30 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_H
# define FT_STRUCT_H

# define TYPE(t)  (t == 's' || t == 'p' || TYPE1(t) || TYPE2(t) || TYPE_UP(t))
# define TYPE1(t) (t == 'i' || t == 'o' || t == 'c' || t == 'd')
# define TYPE2(t) (t == 'u' || t == 'x' || t == 'X'  ||  t == '%')
# define TYPE_UP(t) (t == 'D' || t == 'O' || t == 'U' || t == 'C' || t == 'S')
# define FLAGS(t) (t == '#' || t == '0' || t == '-' || t == '+' || t == ' ')
# define MOD(c) (c == 'h' || c == 'l' || c == 'j' || MOD1(c))
# define MOD1(c) (c == 't' || c == '.' || c == 'z')

# include <stdarg.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct		s_cs
{
	char			index;
	char			flag1;
	char			flag2;
	char			flag3;
	char			flag4;
	char			flag5;
	int				width;
	int				precision;
	char			modifier1;
	char			modifier2;
	char			type;
	int				digit;
}					t_cs;

#endif
