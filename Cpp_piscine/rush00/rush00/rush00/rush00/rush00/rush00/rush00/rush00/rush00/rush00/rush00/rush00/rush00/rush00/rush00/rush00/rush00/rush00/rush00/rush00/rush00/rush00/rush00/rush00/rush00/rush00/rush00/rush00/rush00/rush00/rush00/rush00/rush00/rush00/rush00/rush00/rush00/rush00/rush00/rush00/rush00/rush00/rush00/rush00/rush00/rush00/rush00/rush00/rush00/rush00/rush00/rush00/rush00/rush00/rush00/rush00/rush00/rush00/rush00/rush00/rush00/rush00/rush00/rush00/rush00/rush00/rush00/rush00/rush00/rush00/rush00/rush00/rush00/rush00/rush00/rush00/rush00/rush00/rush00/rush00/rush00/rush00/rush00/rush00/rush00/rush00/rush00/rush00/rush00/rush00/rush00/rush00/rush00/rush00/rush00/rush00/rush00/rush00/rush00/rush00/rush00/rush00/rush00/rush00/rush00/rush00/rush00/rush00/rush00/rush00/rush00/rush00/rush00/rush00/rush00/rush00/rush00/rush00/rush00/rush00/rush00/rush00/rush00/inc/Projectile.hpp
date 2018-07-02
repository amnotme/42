/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Projectile.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 16:05:33 by lhernand          #+#    #+#             */
/*   Updated: 2018/07/02 05:03:53 by sgardner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PROJECTILE_H
# define PROJECTILE_H
# include <iostream>

class Projectile : public virtual Entity {

public:
  Projectile(void);
  ~Projectile(void);
  Projectile	&operator=(Projectile const & rhs);

protected:

};

#endif
