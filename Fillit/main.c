/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <gmalpart@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 22:47:30 by gmalpart          #+#    #+#             */
/*   Updated: 2017/11/30 16:40:32 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int argc, char **argv)
{
	if (argc != 2)
		fillit_print_usage(argv[0]);
	else
		fillit_run(argv[1]);
	return (0);
}
