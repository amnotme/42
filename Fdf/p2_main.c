/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p2_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 19:32:40 by lhernand          #+#    #+#             */
/*   Updated: 2017/12/19 20:15:39 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct		s_list
{
	void			*data;
	int				x[2];
	int				y[2];
	struct s_list	*next;
}					t_list;

typedef struct		s_diff
{
	int				dx;
	int				dy;
	struct s_diff	*next;
}					t_diff;


t_diff		*create_diff(int dx, int dy)
{
	t_diff	*head;

	head = (t_diff *)malloc(sizeof(t_diff));
	head->dx = dx;
	head->dy = dy;
	head->next = NULL;
	return (head);
}

t_list	 	*create(void *data, int x[2], int y[2])
{
	t_list	*head;

	head = (t_list *)malloc(sizeof(t_list));
	head->data = data;
	head->x[0] = x[0];
	head->x[1] = x[1];
	head->y[0] = y[0];
	head->y[1] = y[1];
	head->next = NULL;
	return (head);
}

void		push2(t_diff **list, int dx, int dy)
{
	t_diff *node;

	if (*list)
	{
		node = *list;
		while (node->next)
			node = node->next;
		node->next = create_diff(dx, dy);
	}
	else
		*list = create_diff(dx, dy);
}

void		push(t_list **list, void *data, int x[2], int y[2])
{
	t_list *node;

	if (*list)
	{
		node = *list;
		while (node->next)
			node = node->next;
		node->next = create(data, x, y);
	}
	else
		*list = create(data, x, y);

}

void		print(t_list **lst)
{
	t_list *tmp;

	tmp = *lst;
	while (tmp->next)
	{
		printf("%s  x1 -> %d x2 %d y1 -> %d y2 -> %d\n", tmp->data, tmp->x[0], \
				tmp->x[1], tmp->y[0], tmp->y[1]);
		tmp = tmp->next;
	}
	printf("%s  x1 -> %d x2 %d y1 -> %d y2 -> %d\n", tmp->data, tmp->x[0], \
				tmp->x[1], tmp->y[0], tmp->y[1]);
}

void		print2(t_diff **lst)
{
	t_diff *tmp;

	tmp = *lst;
	while (tmp->next)
	{
		printf("dx -> %d dy -> %d\n", tmp->dx, tmp->dy);
		tmp = tmp->next;
	}
	printf("dx -> %d dy -> %d\n", tmp->dx, tmp->dy);
}

int			main(void)
{
	char *str = "x2 - x1 = dx; y2 - y1 = dy";
	int x[2] = {3, 6};
	int x2[2] = {6, 12};
	int y[2] = {5, 7};
	int y2[2] = {7, 14};
	int x3[2] = {12, 21};
	int y3[2] = {23, 33};
//	int dx;
//	int dy;
	t_list *list;
	t_diff *dif;

	dif = NULL;
	list = NULL;
	push(&list, str, x, y);
	push2(&dif, (list->x[1] - list->x[0]), (list->y[1] - list->y[0]));
	push(&list , str, x2, y2);	
	push2(&dif, (list->next->x[1] - list->next->x[0]), (list->next->y[1] - list->next->y[0]));
	push(&list , str, x3, y3);	
	push2(&dif, (list->next->next->x[1] - list->next->next->x[0]), (list->next->next->y[1] - list->next->next->y[0]));
	print(&list);
	print2(&dif);
	return (0);
}


