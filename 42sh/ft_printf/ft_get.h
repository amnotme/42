/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 00:32:46 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/04 23:28:30 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_H
# define FT_GET_H

# include "ft_struct.h"

int		ft_get_type(char *str, t_cs *cs);
int		ft_get_flags(char *str, t_cs *cs);
int		ft_get_width(char *str, t_cs *cs);
int		ft_get_prec(char *str, t_cs *cs);
int		ft_get_mod(char *str, t_cs *cs);

#endif
