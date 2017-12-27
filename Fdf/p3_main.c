/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p3_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leopoldohernandez <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 01:13:38 by leopoldoh         #+#    #+#             */
/*   Updated: 2017/12/27 02:42:04 by leopoldoh        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
typedef struct      s_lst
{
    int             x[2];
    int             y[2];
    struct s_lst   *next;
}                   t_lst;

t_lst      *create(int x[2], int y[2])
{
    t_lst *head;

    head = (t_lst *)malloc(sizeof(t_lst));
    head->x[0] = x[0];
    head->x[1] = x[1];
    head->y[0] = y[0];
    head->y[1] = y[1];
    head->next = NULL;
    return (head);
}

void        push(t_lst **list, int x[2], int y[2])
{
    t_lst *node;

    if (*list)
    {
        node = *list;
        while (node->next)
            node = node->next;
        node->next = create(x, y);
    }
    else
        *list = create(x, y);
}

void        print(t_lst **list)
{
    t_lst *node;

    node = *list;
    while (node->next)
    {
        printf("x1, x2, y1, y2 ->  %d, %d, %d, %d\n", node->x[0], node->x[1], node->y[0], node->y[1]);
        node = node->next;
    }
        printf("x1, x2, y1, y2 ->  %d, %d, %d, %d\n", node->x[0], node->x[1], node->y[0], node->y[1]);
}

int      get_width(char *line)
{
    unsigned int i;
    unsigned int w;
    i = 0;
    w = 0;
    while (line[i])
    {
        if ((line[i] == ' ') || (line[i] == '\n'))
            w++;
        i++;
    }
    return (w + 1);
}

int         main(int argc, char **argv)
{   
    int x1[2] = {2, 2};
    int x2[2] = {2, 2};
    int x3[2] = {1, 1};
    int y1[2] = {3, 3};
    int y2[2] = {4, 4};
    int y3[2] = {5, 5};
    int fd;
    char *line;
    int h;
    int w;
    h = 1;
    w = 0;
    t_lst *lst;
    t_lst *lst2;
    lst2 = NULL;
    lst = NULL;
    push(&lst, x1, y1);
    push(&lst, x2, y2);
    push(&lst, x3, y3);

    if (argc == 1)
        print(&lst);
    else if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        while (get_next_line(fd, &line))
        {
            w += get_width(line);
            if (get_width(line) != (w / h))
                printf("calaqueo\n");
            printf("%s h-> %d w -> %d\n", line, h, (w / h));
            h++;
            free(line);
        }
    }
    else 
        return (-1);
    if (argc == 2)
        close(fd);
    return (0);
}
