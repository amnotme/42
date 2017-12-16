/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl10.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 15:39:22 by lhernand          #+#    #+#             */
/*   Updated: 2017/12/15 15:39:26 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int  main(void)
{
  char  *line = NULL;
  int   fd = open("gnl10.txt", O_RDONLY);
  get_next_line(fd, &line);
  close(fd);
  sleep(15);
  return (0);
}
