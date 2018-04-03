/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 19:53:45 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/03 22:50:58 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include "struct.h"
# include "ft_liste.h"

char	*ft_format_year(char *str);
char	*ft_format_time(char *str);
char	*ft_format_chmod(mode_t mode);
char	ft_format_type(t_liste *node);
char	*ft_concat_path(char *parent, char *str);

#endif
