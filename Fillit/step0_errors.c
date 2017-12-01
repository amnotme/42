/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step0_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <gmalpart@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 03:09:23 by gmalpart          #+#    #+#             */
/*   Updated: 2017/11/30 18:40:17 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Printing regular usage.
*/

void		fillit_print_usage(char *arg)
{
	ft_putstr("usage ");
	ft_putstr(arg);
	ft_putstr(" fillit_file\n");
}

/*
** General Exit.
*/

void		fillit_print_error(int error_code)
{
	if (error_code < 0)
		ft_putstr("error\n");
	exit(error_code);
}
