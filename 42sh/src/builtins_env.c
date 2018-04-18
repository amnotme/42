/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 07:11:01 by asarandi          #+#    #+#             */
/*   Updated: 2018/04/15 14:35:38 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft.h"

int		builtin_setenv_kv(t_shell *sh, char **argv, int arg_count)
{
	char	*key;
	char	*value;

	key = argv[1];
	value = EMPTY_STRING;
	if (arg_count == 3)
		value = argv[2];
	if (is_alphanumeric_string(key) == 1)
	{
		if (ft_isalpha(key[0]))
		{
			kv_array_set_key_value(&sh->envp, key, value);
			return (0);
		}
		else
			ft_printf(STDERR_FILENO, "setenv: %s\n", E_LETTER);
	}
	else
		ft_printf(STDERR_FILENO, "setenv: %s\n", E_ALNUM);
	return (1);
}

int		builtin_setenv(t_shell *sh, char **argv)
{
	int		count;

	count = count_char_array(argv);
	if (count == 1)
		return (builtin_env(sh, argv));
	else if (count == 2)
		return (builtin_setenv_kv(sh, argv, 2));
	else if (count == 3)
		return (builtin_setenv_kv(sh, argv, 3));
	else if (count > 3)
	{
		ft_printf(STDERR_FILENO, "setenv: %s\n", E_TOOMANY);
		return (1);
	}
	return (0);
}

int		builtin_unsetenv(t_shell *sh, char **argv)
{
	char	*key;
	int		i;
	int		count;

	count = count_char_array(argv);
	i = 1;
	while (i < count)
	{
		key = argv[i];
		kv_array_remove_key(sh->envp, key);
		i++;
	}
	if (i == 1)
	{
		ft_printf(STDERR_FILENO, "unsetenv: %s\n", E_TOOFEW);
		return (1);
	}
	return (0);
}

int		builtin_env(t_shell *sh, char **argv)
{
	int	i;

	i = 0;
	argv[1] += 0;
	while (sh->envp[i] != NULL)
	{
		ft_printf(STDOUT_FILENO, "%s\n", sh->envp[i]);
		i++;
	}
	return (0);
}
