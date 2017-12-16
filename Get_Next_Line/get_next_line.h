/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 02:28:51 by lhernand          #+#    #+#             */
/*   Updated: 2017/12/14 12:16:56 by leopoldoh        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <unistd.h>



# define BUFF_SIZE 8
# define DESCRIPTORS 4864
# define MAX_FD 1025
# define RET_VALUE(ret) ret > 0 ? 1 : ret

int			get_next_line(const int fd, char **line);

#endif
