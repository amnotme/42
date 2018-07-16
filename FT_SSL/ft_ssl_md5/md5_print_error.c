/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_print_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 20:28:40 by lhernand          #+#    #+#             */
/*   Updated: 2018/07/16 03:24:12 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

void			md5_print_error(int error_code)
{
	if (error_code == -1)
		ft_putendl("Open Error");
	else if (error_code == -2)
		ft_putendl("Malloc Error");
	else if (error_code == -3)
		ft_putendl("Read Error");
	else if (error_code == -4)
		ft_putendl("Format Error");
	else
		ft_putendl("Error");
	exit(error_code);
}

void			md5_print_usage_no_params(void)
{
	ft_putendl("usage: ft_ssl command [command opts] [command args]");
	return ;
}

void			md5_print_usage_invalid_params(char *arg)
{
	ft_putstr("ft_ssl: Error: '");
	ft_putstr(arg);
	ft_putendl("' is an invalid command.");
	ft_putendl("\nStandard Commands:");
	ft_putendl("\nMessage Digest commands:");
	ft_putendl("md5");
	ft_putendl("sha256");
	ft_putendl("\nCipher commands:");
}
