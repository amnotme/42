/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 22:44:18 by sgardner          #+#    #+#             */
/*   Updated: 2018/07/02 06:10:01 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

/*
** PUBLIC
*/

Game::Game(void)
{
	Game::_game = this;
	this->_init(30);
}

Game::Game(uint8_t tps)
{
	Game::_game = this;
	this->_init(tps);
}

Game::Game(Game const &obj)
{
	this->_init(obj.getTicksPerSecond());
	*this = obj;
}

Game::~Game(void)
{
	endwin();
	delete (this->getPlayer());
	delete (this->getWindow());
}

Game		&Game::operator=(Game const &obj)
{
	*this->getWindow() = *obj.getWindow();
	return (*this);
}

Player		*Game::getPlayer(void) const
{
	return (this->_player);
}

Window		*Game::getWindow(void) const
{
	return (this->_win);
}

uint64_t	Game::getTicks(void) const
{
	return (this->_ticks);
}

uint8_t		Game::getTicksPerSecond(void) const
{
	return (this->_tps);
}

void		Game::setTicksPerSecond(uint8_t tps)
{
	this->_tps = tps;
	if (tps > 1)
	{
		this->_tick_delay.tv_sec = 0;
		this->_tick_delay.tv_nsec = 1000000000 / tps;
	}
	else
	{
		this->_tick_delay.tv_sec = 1;
		this->_tick_delay.tv_nsec = 0;
	}
}

#define MSEC(ts)	(ts.tv_sec * 1000) + (ts.tv_nsec / 1000000)

void		Game::loop(void)
{
	Player		*p;
	Projectile	*bullet;
	Window		*win;
	WINDOW		*view;
	t_timespec	t1;
	t_timespec	t2;
	int			key;

	p = this->getPlayer();
	win = this->getWindow();
	view = win->getView();
	clock_gettime(CLOCK_MONOTONIC_RAW, &t1);
	wtimeout(view, MSEC(this->_tick_delay));
	while (this->_run)
	{
		if ((key = wgetch(view)) != ERR)
			this->_processInput(key);
		clock_gettime(CLOCK_MONOTONIC_RAW, &t2);
		t2 = this->_timeDiff(this->_tick_delay, this->_timeDiff(t2, t1));
		if (t2.tv_sec < 0 || (!t2.tv_sec && !t2.tv_nsec))
		{
			++this->_ticks;
			// Process game state
			win->drawStars();
			win->updateBorders();
			int	i = 0;
			while (i < p->getNumBullets())
			{
				bullet = p->getBullets()[i];
				if (bullet->advance())
				{
					p->removeBullet();
					continue ;
				}
				win->drawEntity(*bullet);
				++i;
			}
			win->drawEntity(*p);
			win->redraw();
			clock_gettime(CLOCK_MONOTONIC_RAW, &t1);
			wtimeout(view, MSEC(this->_tick_delay));
		}
		else
			wtimeout(view, MSEC(t2));
	}
}

/*
** PRIVATE
*/

void		Game::_init(int tps)
{
	initscr();
	refresh();
	cbreak();
	noecho();
	curs_set(0);
	this->_run = true;
	this->_ticks = 0;
	this->setTicksPerSecond(tps);
	this->_win = new Window(*this);
	this->_player = new Player();
	keypad(this->getWindow()->getView(), TRUE);
}

void		Game::_processInput(int key)
{
	switch (key)
	{
		case KEY_UP:
			this->getPlayer()->moveUp();
			break ;
		case KEY_DOWN:
			this->getPlayer()->moveDown();
			break ;
		case KEY_LEFT:
			this->getPlayer()->moveLeft();
			break ;
		case KEY_RIGHT:
			this->getPlayer()->moveRight();
			break ;
		case ' ':
			this->getPlayer()->shoot(-1);
			break ;
		case 'q':
			this->_run = false;
			break ;
		default:
			break ;
	}
}

t_timespec	Game::_timeDiff(t_timespec t1, t_timespec t2)
{
	t1.tv_sec -= t2.tv_sec;
	if ((t1.tv_nsec -= t2.tv_nsec) < 0)
	{
		--t1.tv_sec;
		t1.tv_nsec += 1000000000;
	}
	return (t1);
}

/*
** STATIC
*/

Game	*Game::_game = nullptr;

Game const	*Game::getGame(void)
{
	return (Game::_game);
}
