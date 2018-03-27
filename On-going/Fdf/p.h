/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 17:16:03 by lhernand          #+#    #+#             */
/*   Updated: 2017/12/19 18:22:04 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_H
# define P_H
# include <stdlib.h>
# include <stdio.h>

typedef struct		s_list
{
	void			*data;
	int				x;
	int				y;
	struct s_list	*next;
}					t_list;

t_list		*create(void *data, int x, int y);
void		print(t_list **list);
void		push(t_list **list, void *node, int x, int y);

#endif
