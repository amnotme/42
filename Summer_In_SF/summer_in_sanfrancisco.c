/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   summer_in_sanfrancisco.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:44:44 by lhernand          #+#    #+#             */
/*   Updated: 2017/11/17 18:53:57 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void 	blue(void)
{
	ft_putstr("\033[1;34m");
}

void	cyan(void)
{
	ft_putstr("\033[0;36m");
}

void 	bblue(void)
{
	ft_putstr("\033[0;34m");
}

void 	white(void)
{
	ft_putstr("\033[0m");
}
void	cloud(int i)
{

	int j;
	j = i;
	if (i == 0 || i < 0)
	{
		ft_putchar('\n');
		return ;
	}
	blue();
	while (j > 0)
	{
		if (j == 1)
			ft_putstr("  ~^~^~^~\n");
		else
			ft_putstr("  ~^~^~^~ ");
		j--;
	}
	j = i;
	white();
	while (j > 0)
	{

		if (j == 1)
			ft_putstr("~^{CLOUD}^~\n");
		else
			ft_putstr("~^{CLOUD}^");
		j--;
	}
	j = i;
	while (j > 0)
	{

		if (j == 1)
			ft_putstr("~^{CLOUD}^~\n");
		else
			ft_putstr("~^{CLOUD}^");
		j--;
	}
	j = i;
	blue();
	while (j > 0)
	{

		if (j == 1)
			ft_putstr("  ~^~^~^~\n");
		else
			ft_putstr("  ~^~^~^~ ");
		j--;
	}
}

void	rain(int i)
{
	int j;
	int start;
	int times;
	int iteration;
	times = i + 2;
	j = i;

	start = (5 * j) - 1;
	while (times > 0)
	{
		iteration = start;
		while (iteration > 0 && times > 0)
		{
			if (iteration % 2 == 0)
				bblue();
			else
				cyan();

			if (iteration > 1)
				ft_putstr(" /");
			else if (iteration == 1)
				ft_putstr(" /\n");
			iteration--;
		}
		times--;
		iteration = start;
		while (iteration > 0 && times > 0)
		{
			if (iteration % 2 == 0)
				bblue();
			else
				cyan();

			if (iteration > 1)
				ft_putstr("/ ");
			else if (iteration == 1)
				ft_putstr("/\n");
			iteration--;
		}
		times--;
		start--;
	}
}

void	summer_in_sanfrancisco(char *number)
{
	int clouds;

	clouds = atoi(number);
	cloud(clouds);
	rain(clouds);
	white();
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("usage: ");
	   	ft_putstr(argv[0]);
		ft_putstr(" [integer]\n");
	}
	else
		summer_in_sanfrancisco(argv[1]);
	return (0);
}
