/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 01:57:55 by lhernand          #+#    #+#             */
/*   Updated: 2018/07/02 04:59:06 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ENEMY_H
# define ENEMY_H
# include "Entity.hpp"
# include <iostream>

class Enemy : public virtual Entity {

  public:
    Enemy(void);
    ~Enemy(void);
    Enemy	&operator=( Enemy const & rhs );

  protected:

};

#endif
