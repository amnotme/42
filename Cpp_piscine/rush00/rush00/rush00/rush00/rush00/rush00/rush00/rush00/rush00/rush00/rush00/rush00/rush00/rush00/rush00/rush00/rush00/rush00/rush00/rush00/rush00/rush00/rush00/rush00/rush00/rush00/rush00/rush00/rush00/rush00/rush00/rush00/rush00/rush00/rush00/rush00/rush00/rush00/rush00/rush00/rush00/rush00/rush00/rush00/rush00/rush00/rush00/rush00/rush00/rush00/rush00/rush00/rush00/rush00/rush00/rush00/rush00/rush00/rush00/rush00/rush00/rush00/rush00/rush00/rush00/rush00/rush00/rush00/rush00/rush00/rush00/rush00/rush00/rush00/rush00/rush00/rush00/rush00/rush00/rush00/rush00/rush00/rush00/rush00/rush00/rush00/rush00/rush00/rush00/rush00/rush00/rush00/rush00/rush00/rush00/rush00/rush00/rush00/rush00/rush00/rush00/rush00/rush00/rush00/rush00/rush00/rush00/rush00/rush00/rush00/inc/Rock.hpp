/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rock.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 01:59:09 by lhernand          #+#    #+#             */
/*   Updated: 2018/07/02 05:21:29 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROCK_H
# define ROCK_H
# include <iostream>
# include <string>

class Rock : public virtual Entity {

  public:
    Rock(void);
    ~Rock(void);
    Rock & operator=( Rock const & rhs );

  protected:

};

#endif
