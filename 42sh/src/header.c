/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztisnes <ztisnes@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 17:24:17 by ztisnes           #+#    #+#             */
/*   Updated: 2018/04/15 17:00:03 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft.h"

void	cmd_title(void)
{
	ft_printf(STDOUT_FILENO, "******************\n");
	ft_printf(STDOUT_FILENO, "*                *\n");
	ft_printf(STDOUT_FILENO, "*    Help menu   *\n");
	ft_printf(STDOUT_FILENO, "*                *\n");
	ft_printf(STDOUT_FILENO, "******************\n");
}

void	header_sh(void)
{
	ft_printf(STDOUT_FILENO, "	   @@@@@@@@     @@\n");
	ft_printf(STDOUT_FILENO, "	@@@                @@\n");
	ft_printf(STDOUT_FILENO, "	@@                   @\n");
	ft_printf(STDOUT_FILENO, "	@@                    @\n");
	ft_printf(STDOUT_FILENO, "	@                    @\n");
	ft_printf(STDOUT_FILENO, "  @			          @\n");
	ft_printf(STDOUT_FILENO, "   #@@	 @@@@        .@\n");
	ft_printf(STDOUT_FILENO, "		 @@@	 @       @@@@@\n");
	ft_printf(STDOUT_FILENO, "			      @      @@    @\'\n");
	ft_printf(STDOUT_FILENO, "			      @     @@      @\n");
	ft_printf(STDOUT_FILENO, "			      @     @@       @\n");
	ft_printf(STDOUT_FILENO, "                @    @@        @\n");
	ft_printf(STDOUT_FILENO, "@             @     @@        @\n");
	ft_printf(STDOUT_FILENO, " @@          @    @          @    /\n");
	ft_printf(STDOUT_FILENO, "  @@@   @@@@@    /'         /'  @@\n");
	ft_printf(STDOUT_FILENO, "	   @@@         @         @@@@\n");
}

void	header_42(void)
{
	ft_printf(1, "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	ft_printf(1, "@@@@@@@@@@@@@@@/        @@@@&       @         @\n");
	ft_printf(1, "@@@@@@@@@@@@@/        @@@@@@&     @@@         @\n");
	ft_printf(1, "@@@@@@@@@@@/        @@@@@@@@&   @@@@@         @\n");
	ft_printf(1, "@@@@@@@@@/        @@@@@@@@@@& @@@@@@@         @\n");
	ft_printf(1, "@@@@@@@/        @@@@@@@@@@@@@@@@@@@@(        @@\n");
	ft_printf(1, "@@@@@/        @@@@@@@@@@@@@@@@@@@@(        @@@@\n");
	ft_printf(1, "@@@/        @@@@@@@@@@@@@@@@@@@@(        @@@@@@\n");
	ft_printf(1, "@/        @@@@@@@@@@@@@@@@@@@@(        @@@@@@@@\n");
	ft_printf(1, "@       ,,,,,,,,,,,,,,,,,@@@&        @@@@@@@@@@\n");
	ft_printf(1, "@                        @@@&        @@@@@@/ @@\n");
	ft_printf(1, "@                        @@@&        @@@@*   @@\n");
	ft_printf(1, "@                        @@@&        @@.     @@\n");
	ft_printf(1, "@@@@@@@@@@@@@@@@,        @@@&        /       @@\n");
	ft_printf(1, "@@@@@@@@@@@@@@@@.        @@@@@@@@@@@@@@@@@@@@@@\n");
	ft_printf(1, "@@@@@@@@@@@@@@@@.        @@@@@@@@@@@@@@@@@@@@@@\n");
	ft_printf(1, "@@@@@@@@@@@@@@@@.        @@@@@@@@@@@@@@@@@@@@@@\n");
	ft_printf(1, "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
}
