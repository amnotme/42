/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 22:05:19 by asarandi          #+#    #+#             */
/*   Updated: 2018/03/31 04:56:06 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_strmatch(char *little, char *big)
{
	int	i;
	int	j;

	i = ft_strlen(little);
	j = ft_strlen(big);
	if (i > j)
		return (0);
	j = 0;
	while (j < i)
	{
		if (little[j] != big[j])
			return (0);
		j++;
	}
	return (1);
}

int	check_more_colors(int fd, char *str)
{
	if (ft_strmatch("{black2}", str))
		return (write(fd, "\033[1;30m", 7));
	if (ft_strmatch("{red2}", str))
		return (write(fd, "\033[1;31m", 7));
	if (ft_strmatch("{green2}", str))
		return (write(fd, "\033[1;32m", 7));
	if (ft_strmatch("{yellow2}", str))
		return (write(fd, "\033[1;33m", 7));
	if (ft_strmatch("{blue2}", str))
		return (write(fd, "\033[1;34m", 7));
	if (ft_strmatch("{magenta2}", str))
		return (write(fd, "\033[1;35m", 7));
	if (ft_strmatch("{cyan2}", str))
		return (write(fd, "\033[1;36m", 7));
	if (ft_strmatch("{white2}", str))
		return (write(fd, "\033[1;37m", 7));
	return (0);
}

int	check_colors(int fd, char *str)
{
	if (ft_strmatch("{eoc}", str))
		return (write(fd, "\033[0;00m", 7));
	if (ft_strmatch("{black}", str))
		return (write(fd, "\033[0;30m", 7));
	if (ft_strmatch("{red}", str))
		return (write(fd, "\033[0;31m", 7));
	if (ft_strmatch("{green}", str))
		return (write(fd, "\033[0;32m", 7));
	if (ft_strmatch("{yellow}", str))
		return (write(fd, "\033[0;33m", 7));
	if (ft_strmatch("{blue}", str))
		return (write(fd, "\033[0;34m", 7));
	if (ft_strmatch("{magenta}", str))
		return (write(fd, "\033[0;35m", 7));
	if (ft_strmatch("{cyan}", str))
		return (write(fd, "\033[0;36m", 7));
	if (ft_strmatch("{white}", str))
		return (write(fd, "\033[0;37m", 7));
	return (check_more_colors(fd, str));
}
