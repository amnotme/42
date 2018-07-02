/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 21:29:40 by sgardner          #+#    #+#             */
/*   Updated: 2018/07/01 15:25:38 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include <iostream>

int	main(void)
{
	Game	*game;

	std::srand(std::time(nullptr));
	game = new Game(30);
	game->loop();
	delete (game);
	return (0);
}
