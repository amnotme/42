/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 22:00:48 by lhernand          #+#    #+#             */
/*   Updated: 2018/04/03 01:13:41 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_struct.h"
#include "ft_printf_header.h"

static void	initialize(int *i, int *flag, int *c)
{
	*flag = 1;
	*i = 1;
	*c = 0;
}

int			builtin_echo(char **params)
{
	int i;
	int flag;
	int c;

	initialize(&i, &flag, &c);
	while (params[c])
		c++;
	if (c == 1)
		return (0);
	if (ft_strcmp(ft_strtrim(params[i]), "-n") == 0)
	{
		flag = 0;
		i++;
	}
	while (params[i])
	{
		if (i == (c - 1))
			ft_printf("%s", params[i++]);
		else
			ft_printf("%s ", params[i++]);
	}
	if (flag != 0)
		ft_putchar('\n');
	return (0);
}

int			main(int argc, char **argv)
{
	(void)argc;
	builtin_echo(argv);
	return (0);
}
