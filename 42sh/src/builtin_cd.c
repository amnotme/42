/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 15:46:44 by asarandi          #+#    #+#             */
/*   Updated: 2018/04/15 14:34:36 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft.h"

char	*builtin_cd_get_path(t_shell *sh, char **argv)
{
	char	*tempo;
	char	*path;

	path = NULL;
	tempo = builtin_cd_get_kv(sh, "HOME");
	if ((argv[1] == NULL) || (ft_strcmp(argv[1], "~") == 0))
	{
		if (tempo != NULL)
			path = ft_strdup(tempo);
	}
	else if (ft_strncmp(argv[1], "~/", 2) == 0)
	{
		if (tempo != NULL)
			path = dir_slash_exec(tempo, &argv[1][2]);
	}
	else if ((ft_strcmp(argv[1], "-")) == 0)
	{
		if ((tempo = builtin_cd_get_kv(sh, "OLDPWD")) != NULL)
			path = ft_strdup(tempo);
	}
	else
		path = ft_strdup(argv[1]);
	return (path);
}

int		builtin_cd_save_cwd(t_shell *sh, char *variable)
{
	char	*cwd;

	cwd = NULL;
	cwd = getcwd(NULL, 0);
	if (cwd != NULL)
	{
		kv_array_set_key_value(&sh->envp, variable, cwd);
		free(cwd);
		return (0);
	}
	else
		perror(SHELL_NAME);
	return (1);
}

int		builtin_cd(t_shell *sh, char **argv)
{
	char	*path;
	int		r;

	if (count_char_array(argv) > 2)
	{
		(void)ft_printf(STDERR_FILENO, E_TOOMANY2, "cd");
		return (1);
	}
	path = builtin_cd_get_path(sh, argv);
	if (path != NULL)
	{
		builtin_cd_save_cwd(sh, "OLDPWD");
		r = chdir(path);
		free(path);
		if (r == -1)
		{
			perror(SHELL_NAME);
			return (1);
		}
		else
			return (builtin_cd_save_cwd(sh, "PWD"));
	}
	return (1);
}
