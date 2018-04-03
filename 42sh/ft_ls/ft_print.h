/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 03:30:45 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/01 20:56:59 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H

# include "struct.h"
# include "ft_liste.h"
# include "ft_utils.h"
# include "ft_helper.h"

void		ft_print(t_liste *node, t_op *op, t_len *len, char *str);
void		ft_print_details(t_liste *node, t_len *len);
void		ft_print_l(t_liste *node, t_len *len, char *tmp);
int			ft_opendir(DIR **dir, char *str);
int			ft_lstat(char *str, char *path, struct stat *sbuf);

#endif
