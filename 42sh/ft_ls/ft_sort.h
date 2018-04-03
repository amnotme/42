/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 18:14:32 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/01 18:30:36 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SORT_H
# define FT_SORT_H

# include "struct.h"
# include "ft_liste.h"

t_liste		*ft_sort(t_liste *head, t_op *op);
t_liste		*ft_sorting(t_liste *head, int (*c)(t_liste *, t_liste *));
t_liste		*ft_sort_rev(t_liste *head);
int			ft_sort_lex(t_liste *current, t_liste *suivant);
int			ft_sort_time(t_liste *current, t_liste *suivant);

#endif
