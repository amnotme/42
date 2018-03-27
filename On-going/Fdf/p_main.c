/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 17:30:15 by lhernand          #+#    #+#             */
/*   Updated: 2017/12/19 19:22:32 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p.h"

void			print(t_list **list)
{
	t_list *tmp;

	tmp = *list;
	while (tmp->next)
	{
		printf("%s  %d %d\n", tmp->data, tmp->x, tmp->y);
		tmp = tmp->next;
	}
	printf("%s  %d %d\n", tmp->data, tmp->x, tmp->y);
}


int				main(void)
{
	char *str = "what the damn hell";
	char *str2 = "WHAT THE DAMN HELL";
	char *str3 = "WTDH";
	
	int	x[3] = {1, 2, 5};
	int y[3] = {2, 4, 5};
	
	int i = 0;
	t_list *ptr;
	ptr = NULL;
	printf("44\n");
	push(&ptr, str, x[i], y[i]);
	printf("46\n");
	i++;
	push(&ptr, str2, x[i], y[i]);
	printf("48\n");
	i++;
	push(&ptr, str3, x[i], y[i]);
	printf("50\n");
	print(&ptr);
	

	return (0);
}
