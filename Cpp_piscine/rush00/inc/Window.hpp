/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardner <stephenbgardner@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 20:38:41 by sgardner          #+#    #+#             */
/*   Updated: 2018/07/01 22:37:55 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_HPP
# define WINDOW_HPP
# include <curses.h>
# include <iostream>

# define DEFAULT_LINES	60
# define DEFAULT_COLS	110

class	Game;

class	Window
{

public:

	Window(Game const &game);
	Window(Game const &game, int nlines, int ncols);
	Window(Window const &obj);
	~Window(void);
	Window		&operator=(Window const &obj);

	Game const	&getGame(void) const;
	WINDOW		*getView(void) const;

	void		drawEntity(Entity const &ent);
	void		drawStars(void);
	void		updateBorders(void) const;
	void		redraw(void) const;

	int 		getCols(void) const;
	int			getLines(void) const;

private:

	void		_init(void);
	void		_generateStars(void);
	void		_generateStarLine(std::string &line) const;

	Game const	&_game;
	int 		_nlines;
	int 		_ncols;
	std::string	*_stars;
	WINDOW 		*_win;
};
#endif
