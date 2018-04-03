/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set1.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 01:12:59 by brabo-hi          #+#    #+#             */
/*   Updated: 2017/12/23 21:22:24 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SET1_H
# define FT_SET1_H

# include "ft_struct.h"
# include "ft_add.h"
# include "ft_convert.h"
# include "ft_helper.h"
# include "ft_find.h"
# include "ft_help.h"

char	*ft_set_s(va_list *args, t_cs *cs);
char	*ft_set_d(va_list *args, t_cs *cs);
char	*ft_set_u(va_list *args, t_cs *cs);
char	*ft_set_c(va_list *args, t_cs *cs);

#endif
