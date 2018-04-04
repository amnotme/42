/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 21:08:12 by brabo-hi          #+#    #+#             */
/*   Updated: 2017/12/26 07:20:50 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32

# include "libft/libft.h"

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

int		get_next_line(const int fd, char **line);
int		ft_contains_end_line(char *str);
int		ft_copy_and_cut(char **str, char **line, int fd);
int		ft_append(char **str, char *buff, int fd, int size);
int		ft_copy_end_file(char **str, char **line, int fd);

#endif
