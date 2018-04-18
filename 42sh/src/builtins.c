/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 05:06:58 by asarandi          #+#    #+#             */
/*   Updated: 2018/04/15 19:34:02 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft.h"

int		builtin_cmd_index(char *cmd)
{
	int			i;
	const char	*builtin_list[] = {
		"echo", "cd", "setenv", "unsetenv", "env", "exit", "help"};

	i = 0;
	while (i < NUM_BUILTINS)
	{
		if (ft_strcmp(cmd, builtin_list[i]) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int		builtin_echo(t_shell *sh, char **argv)
{
	int	dash_n;
	int	i;

	dash_n = 0;
	sh->exit_code += 0;
	if (argv[1] != NULL)
	{
		if (ft_strcmp(argv[1], "-n") == 0)
			dash_n = 1;
		i = 1 + dash_n;
		while (argv[i] != NULL)
		{
			ft_printf(STDOUT_FILENO, "%s", argv[i]);
			if (argv[++i] != NULL)
				ft_printf(STDOUT_FILENO, " ");
		}
	}
	if (dash_n == 0)
		ft_printf(STDOUT_FILENO, "\n");
	return (0);
}

char	*builtin_cd_get_kv(t_shell *sh, char *variable)
{
	char	*result;

	result = NULL;
	result = kv_array_get_key_value(sh->envp, variable);
	if (result == NULL)
		(void)ft_printf(STDERR_FILENO, E_NOVARIABLE, variable);
	return (result);
}

int		builtin_exit(t_shell *sh, char **argv)
{
	int	exit_code;

	if ((argv[1] != NULL) && \
		((is_numeric_string(argv[1])) || \
		((argv[1][0] == '-') && \
		is_numeric_string(&argv[1][1]))))
		exit_code = ft_atoi(argv[1]);
	else
		exit_code = sh->exit_code;
	ft_printf(STDERR_FILENO, "exit\n");
	clean_up(sh);
	exit(exit_code);
	return (exit_code);
}
