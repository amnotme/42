/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_liste.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 03:48:03 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/01/01 18:22:46 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LISTE_H
# define FT_LISTE_H

# include "struct.h"

typedef struct		s_liste
{
	struct dirent	*rep;
	struct stat		*sbuf;
	struct s_liste	*next;
}					t_liste;

t_liste				*ft_liste_new(struct dirent *rep, struct stat *buf);
t_liste				*ft_liste_add(t_liste *head,
		t_liste *node, struct s_len *len, t_op *op);
void				ft_liste_clear(t_liste *head, t_len **len);

#endif
