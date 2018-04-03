/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 22:00:48 by lhernand          #+#    #+#             */
/*   Updated: 2018/03/30 11:27:17 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_struct.h"

int			echo(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc == 1)
		ft_putchar('\n');
	else if (argc != 1)
	{
		while(i < argc)
		{
			if (i < argc -1)
				ft_printf("%s ", argv[i])
			else
				ft_printf("%s", argv[i]);
			i++;
		}
		ft_putchar('\n');
	}
	return (0);	
}
