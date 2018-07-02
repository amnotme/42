/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 22:43:58 by sgardner          #+#    #+#             */
/*   Updated: 2018/07/02 05:06:27 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP
# include "Entity.hpp"
# include "Projectile.hpp"
# include "Enemy.hpp"
# include "Player.hpp"
# include "Rock.hpp"
# include "Window.hpp"
# include <curses.h>
# include <time.h>
# include <cstdint>
# include <iostream>

typedef struct timespec	t_timespec;

class	Game
{

public:

	Game(void);
	Game(uint8_t tps);
	Game(Game const &obj);
	~Game(void);
	Game				&operator=(Game const &obj);

	static Game const	*getGame(void);
	Player				*getPlayer(void) const;
	Window				*getWindow(void) const;

	uint64_t			getTicks(void) const;
	uint8_t				getTicksPerSecond(void) const;
	void				setTicksPerSecond(uint8_t tps);
	void				loop(void);

private:

	void				_init(int tps);
	void				_processInput(int key);
	t_timespec			_timeDiff(t_timespec t1, t_timespec t2);

	static Game 		*_game;
	Player				*_player;
	Window				*_win;
	t_timespec			_tick_delay;
	uint64_t			_ticks;
	uint8_t				_tps;
	bool				_run;
};
#endif
