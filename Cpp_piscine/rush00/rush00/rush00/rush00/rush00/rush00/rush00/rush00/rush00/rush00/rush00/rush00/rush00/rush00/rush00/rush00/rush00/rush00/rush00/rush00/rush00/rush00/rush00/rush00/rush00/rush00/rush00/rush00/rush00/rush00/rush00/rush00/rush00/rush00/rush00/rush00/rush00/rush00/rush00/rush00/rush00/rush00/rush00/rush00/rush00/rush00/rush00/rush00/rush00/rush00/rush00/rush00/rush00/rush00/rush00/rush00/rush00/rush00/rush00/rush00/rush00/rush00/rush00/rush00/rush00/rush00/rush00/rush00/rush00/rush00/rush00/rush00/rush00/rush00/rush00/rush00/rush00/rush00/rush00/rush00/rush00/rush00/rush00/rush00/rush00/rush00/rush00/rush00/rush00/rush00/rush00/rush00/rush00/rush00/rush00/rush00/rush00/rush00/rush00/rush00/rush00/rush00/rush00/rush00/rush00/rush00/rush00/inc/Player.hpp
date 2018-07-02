/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 01:58:20 by lhernand          #+#    #+#             */
/*   Updated: 2018/07/02 05:16:15 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H
# include <iostream>
# include <string>

class	Player : public Entity
{

  public:

	Player(void);
	~Player(void);
	Player	&operator=(Player const &rhs);

	int		getLives(void) const;
	void	setLives(int lives);

	int		getScore(void) const;
	void	setScore(int score);

    void	moveLeft(void);
    void	moveRight(void);
    void	moveUp(void);
    void	moveDown(void);

  private:

	int		_lives;
	int		_score;
};

#endif
