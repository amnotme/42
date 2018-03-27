/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leopoldohernandez <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 03:14:29 by leopoldoh         #+#    #+#             */
/*   Updated: 2018/01/05 22:34:35 by leopoldoh        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

int         main(int argc, char **argv)
{
    char **temp;
    int i;
    int fd;
    char *line;

    if (argc != 2)
        exit(0);
    else
        fd = open(argv[1], O_RDONLY);
    while (get_next_line(fd, &line))
    {
        i = 0;
        temp = ft_strsplit(line, ' ');
        while (temp[i])
        {
            printf("%s ", temp[i]);
            i++;
        }
        printf("\n");
        free(line);
    }
    close(fd);

    return (0);
}


