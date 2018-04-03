/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 22:02:39 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/01 19:03:29 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>

# include "struct.h"
# include "ft_get.h"
# include "ft_liste.h"
# include "ft_print.h"
# include "ft_utils.h"
# include "ft_sort.h"

void	ft_parse_args(t_op *op, char *str);
void	ft_parse_liste(t_liste *head, t_op *op, t_len *len, char *str);
void	ft_parse_dir(t_liste *head, t_op *op, char *parent);
t_len	*ft_initialize_len(void);

#endif
