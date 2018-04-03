/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 03:44:23 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/01 22:15:18 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_H
# define FT_GET_H

# define USAGE  "usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]"

# include "struct.h"
# include "ft_liste.h"
# include "ft_utils.h"

int		ft_get_dir_len(char *str);
void	ft_get_op(t_op *op, char *argv);
int		ft_get_nbr(int n);
int		ft_get_size(t_liste *head);
void	ft_get_len(t_liste *head, t_len *len);

#endif
