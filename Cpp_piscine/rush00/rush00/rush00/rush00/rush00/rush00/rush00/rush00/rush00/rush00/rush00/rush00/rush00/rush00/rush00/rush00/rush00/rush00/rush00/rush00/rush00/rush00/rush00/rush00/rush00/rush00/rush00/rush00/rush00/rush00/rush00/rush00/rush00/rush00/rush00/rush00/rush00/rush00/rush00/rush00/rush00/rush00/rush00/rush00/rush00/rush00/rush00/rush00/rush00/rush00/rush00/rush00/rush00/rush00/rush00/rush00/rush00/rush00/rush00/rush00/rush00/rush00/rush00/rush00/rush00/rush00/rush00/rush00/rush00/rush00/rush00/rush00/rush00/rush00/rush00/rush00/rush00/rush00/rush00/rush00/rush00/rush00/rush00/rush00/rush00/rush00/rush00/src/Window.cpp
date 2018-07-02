/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 20:41:01 by sgardner          #+#    #+#             */
/*   Updated: 2018/07/02 06:12:57 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"

/*
** PUBLIC
*/

Window::Window(Game const &game) :
	_game(game),
	_nlines(DEFAULT_LINES + 1),
	_ncols(DEFAULT_COLS + 2)
{
	this->_init();
}

Window::Window(Game const &game, int nlines, int ncols) :
	_game(game),
	_nlines(nlines + 1),
	_ncols(ncols + 2)
{
	this->_init();
}

Window::Window(Window const &obj) :
	_game(obj.getGame())
{
	*this = obj;
}

Window::~Window(void)
{
	delete [] this->_stars;
	delwin(this->getView());
}

Window		&Window::operator=(Window const &obj)
{
	this->_nlines = obj.getLines();
	this->_ncols = obj.getCols();
	wresize(this->_win, this->_nlines, this->_ncols);
	this->redraw();
	return (*this);
}

Game const	&Window::getGame(void) const
{
	return (this->_game);
}

WINDOW		*Window::getView(void) const
{
	return (this->_win);
}

void		Window::drawEntity(Entity const &ent)
{
	WINDOW				*win;
	char const *const	*sprite;
	int					locX;
	int					locY;

	win = this->getView();
	sprite = ent.getSprite();
	locX = ent.getPosX() - (ent.getSpriteWidth() / 2);
	locY = ent.getPosY() - (ent.getSpriteLength() / 2);
	for (int row = 0; row < ent.getSpriteLength(); row++)
	{
		wmove(win, locY + row, locX);
		for (int col = 0; col < ent.getSpriteWidth(); col++)
		{
			if (sprite[row][col] == '#')
				waddch(win, ' ' | A_REVERSE);
			else if (sprite[row][col] == '|')
				waddch(win, '|' | A_BOLD);
			else
				wmove(win, locY + row, locX + col + 1);
		}
	}
}

void		Window::drawStars(void)
{
	static int	start = 0;
	std::string	*stars;
	WINDOW		*win;
	int			lines;

	stars = this->_stars;
	win = this->getView();
	lines = this->getLines() - 1;
	if (!(this->getGame().getTicks() % 2))
		start = (start + lines - 1) % lines;
	this->_generateStarLine(stars[(start + lines) % lines]);
	for (int i = 0; i < lines; i++)
	{
		wmove(win, i, 1);
		waddstr(win, stars[(start + i) % lines].c_str());
	}
}

void		Window::updateBorders(void) const
{
	Player		*p;
	WINDOW		*win;
	int			cols;
	int			lines;
	int			options;

	p = this->getGame().getPlayer();
	win = this->getView();
	cols = this->getCols();
	lines = this->getLines();
	options = A_REVERSE | A_BOLD;
	wattron(win, options);
	wmove(win, 0, 0);
	wvline(win, ' ', lines);
	wmove(win, 0, cols - 1);
	wvline(win, ' ', lines);
	wmove(win, lines - 1, 0);
	whline(win, ' ', cols);
	wprintw(win, "  LIVES %d | SCORE %.10d | TIME %d",
		p->getLives(),
		p->getScore(),
		this->getGame().getTicks() / this->getGame().getTicksPerSecond());
	wattroff(win, options);
}

void		Window::redraw(void) const
{
	wrefresh(this->getView());
}

int			Window::getCols(void) const
{
	return (this->_ncols);
}

int			Window::getLines(void) const
{
	return (this->_nlines);
}

/*
** PRIVATE
*/

void		Window::_init(void)
{
	this->_generateStars();
	this->_win = newwin(this->_nlines, this->_ncols, 0, 0);
}

void		Window::_generateStars(void)
{
	int	lines;

	lines = this->_nlines;
	this->_stars = new std::string[lines];
	for (int i = 0; i < lines; i++)
		this->_generateStarLine(this->_stars[i]);
}

void		Window::_generateStarLine(std::string &line) const
{
	int	length;

	line.clear();
	length = this->getCols() - 2;
	for (int i = 0; i < length; i++)
	{
		if (!(std::rand() % 25))
			line += ACS_DIAMOND;
		else
			line += " ";
	}
}
