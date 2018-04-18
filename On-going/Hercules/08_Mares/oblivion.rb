#!/usr/bin/env ruby
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    oblivion.rb                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/10 14:23:40 by lhernand          #+#    #+#              #
#    Updated: 2018/04/10 14:23:40 by lhernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# the horses are dropping poop everywhere... Let's clean it up

system("rm -rf *.poo")

# Let's kill all processes that are being run by the user.  This will close...
# Everything

system("killall -u $USER")
