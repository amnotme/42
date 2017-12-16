/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl4_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 15:51:05 by lhernand          #+#    #+#             */
/*   Updated: 2017/12/15 15:51:19 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "get_next_line.h"

/*
** 2 lines via STDIN with 16 chars with Line Feed
*/

int				main(void)
{
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	int			errors;

	fd = 0;
	count_lines = 0;
	errors = 0;
	line = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (count_lines == 0 && strcmp(line, "1234567890abcde") != 0)
			errors++;
		if (count_lines == 1 && strcmp(line, "fghijklmnopqrst") != 0)
			errors++;
		count_lines++;
		if (count_lines > 50)
			break ;
	}
	if (count_lines != 2)
		printf("-> must have returned '1' twice instead of %d time(s)\n", count_lines);
	if (errors > 0)
		printf("-> must have read \"1234567890abcde\" and \"fghijklmnopqrst\"\n");
	if (count_lines == 2 && errors == 0)
		printf("OK\n");
	return (0);
}
