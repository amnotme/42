/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 22:58:15 by brabo-hi          #+#    #+#             */
/*   Updated: 2017/12/21 22:59:33 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FIND_H
# define FT_FIND_H

# include "ft_struct.h"

int	ft_find_max(t_cs *cs, int min, int prefix);
int	ft_find_min(t_cs *cs, int len, int prefix);
int	ft_find_zero(t_cs *cs, char *dest, char prefix, int min);

#endif
