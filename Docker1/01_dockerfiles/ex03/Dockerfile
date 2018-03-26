# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/26 02:55:55 by lhernand          #+#    #+#              #
#    Updated: 2018/03/26 02:58:18 by lhernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#
# Design a Dockerfile that gets the development version of Gogs, installs it
# with all the dependencies and the necessary configurations, and launches the
# application, all as it builds. The container will be deemed valid if you can
# access the web client, and if you can interact via GIT with this container.
#

FROM    golang

EXPOSE  3000

RUN     adduser --disabled-login --gecos 'Gogs' git
RUN     apt-get update && \
        DEBIAN_FRONTEND=noninteractive apt-get install mysql-server -y && \
        service mysql start && mysql -uroot -e "create database gogs"

USER    git

RUN     mkdir -p $GOPATH/src/github.com/gogits && \
        cd $GOPATH/src/github.com/gogits && \
        git clone --depth=1 -b develop https://github.com/gogits/gogs && \
        cd gogs &&\
        go build .

USER    root

CMD     service mysql start && \
		su git -c "$GOPATH/src/github.com/gogits/gogs/gogs web"
