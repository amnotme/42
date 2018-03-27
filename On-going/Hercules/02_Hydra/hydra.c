/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hydra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 20:22:25 by lhernand          #+#    #+#             */
/*   Updated: 2018/03/03 21:05:53 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>

static int			ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str)
		i++;
	return (i);
}

static void			*ft_memset(void *b, int c, int len)
{
	unsigned char uc;
	unsigned char *su;

	uc = c;
	su = b;
	while (0 < len)
	{
		*su = uc;
		su++;
		len--;
	}
	return ((unsigned char *)b);
}

static void			ft_bzero(void *s, size_t n)
{
	if (n == 0)
		return ;
	ft_memset(s, 0, n);
}

static void			error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}

int					main(int argc, char **argv)
{
	int socket_fd_passed, newsocket_fd, port_no;
	unsigned int size_address;
	char BUFFER[256];
	struct sockaddr_in serv_addr, cli_addr;
	int n;
	if (argc < 2) {
		fprintf(stderr,"ERROR, no port provided\n");
		exit(1);
	}
	socket_fd_passed = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_fd_passed < 0)
		error("ERROR opening socket");
	ft_bzero((char *)&serv_addr, sizeof(serv_addr));

	port_no = atoi(argv[1]);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(port_no);
	if (bind(socket_fd_passed, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
		error("ERROR");
	listen(socket_fd_passed,5);
	size_address = sizeof(cli_addr);
	newsocket_fd = accept(socket_fd_passed, (struct sockaddr *) &cli_addr, &size_address);
	if (newsocket_fd < 0)
		error("ERROR");
	ft_bzero(BUFFER,256);
	n = read(newsocket_fd, BUFFER, 255);
	if (n < 0)
		error("ERROR");
	printf("This is what you passed: %s", BUFFER);
	n = write(newsocket_fd,"pong\npong\n",10);
	if (n < 0)
		error("ERROR");
	return (0);
}
