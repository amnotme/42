/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 23:27:50 by ytuz              #+#    #+#             */
/*   Updated: 2018/04/15 00:02:26 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	check_functions(t_run *run_numbers, char **av, char ***env,
						int *status)
{
	if (ft_strequ(*av, "env") == TRUE)
		*status = builtin_env(av, env);
	else if (ft_strequ(*av, "setenv") == TRUE)
		*status = builtin_setenv(av, env);
	else if (ft_strequ(*av, "unsetenv") == TRUE)
		*status = builtin_unsetenv(av, env);
	else if (ft_strequ(*av, "echo") == TRUE)
		*status = builtin_echo(av, env);
	else if (ft_strequ(*av, "cd") == TRUE)
		*status = builtin_cd(av, env);
	else if (ft_strequ(*av, "exit") == TRUE)
	{
		free(run_numbers);
		*status = builtin_exit(av, env);
	}
	else
		return (FAILURE);
	return (SUCCESS);
}
