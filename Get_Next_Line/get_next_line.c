/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 22:53:16 by lhernand          #+#    #+#             */
/*   Updated: 2017/12/08 01:17:52 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int 		get_next_line(const int fd, char **line)
{

	return (1);
}

int			main(int argc, char **argv)
{
	if (argc != 2)
		ft_putchar('\n');
	else
		while ((get_next_line(fd, line) == 1))
		{
			ft_putendl(line);
			
		}
	return (0);
}
