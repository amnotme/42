/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passef <passef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 09:15:55 by passef            #+#    #+#             */
/*   Updated: 2018/03/29 11:09:34 by passef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int		main(int argc, char **argv)
{
	pid_t	fat;

	fat = fork();
	if (fat > 0)
	{
		wait(NULL);
		printf("fat");
	}
	if (fat == 0)
	{
		sleep(60);
		execve("/bin/ls", argv, NULL);
	}
}