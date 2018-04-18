/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 15:13:20 by asarandi          #+#    #+#             */
/*   Updated: 2018/04/17 21:43:42 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft.h"

void		process_destroy(t_process *p)
{
	if (p->argv != NULL)
		destroy_char_array(p->argv);
	if (p->fullpath != NULL)
		free(p->fullpath);
	free(p);
	return ;
}

t_process	*process_prepare(t_shell *sh, t_ast *ast)
{
	t_process	*p;

	p = ft_memalloc(sizeof(t_process));
	p->argv = build_child_argv_list(sh, ast->name);
	if (p->argv == NULL)
	{
		free(p);
		return (NULL);
	}
	p->ast = ast;
	p->envp = sh->envp;
	return (p);
}

int			process_execute(t_shell *sh, t_process *p)
{
	int			r;
	static int	(*builtin_functions[]) (t_shell *, char **) = {&builtin_echo,
		&builtin_cd, &builtin_setenv, &builtin_unsetenv, &builtin_env,
		&builtin_exit, &builtin_help};

	if (p->argv[0] != NULL)
	{
		if ((r = builtin_cmd_index(p->argv[0])) != -1)
		{
			p->exit_code = builtin_functions[r](sh, p->argv);
		}
		else
		{
			p->exit_code = execute_external_cmd(sh, p);
		}
		return (p->exit_code);
	}
	return (EXIT_FAILURE);
}

void		execute(t_shell *sh, char *cmd)
{
	t_process	*p;

	if ((p = ft_memalloc(sizeof(t_process))) == NULL)
		return ;
	if ((p->argv = build_child_argv_list(sh, cmd)) == NULL)
	{
		free(p);
		return ;
	}
	p->ast = NULL;
	p->envp = sh->envp;
	p->exit_code = process_execute(sh, p);
	sh->exit_code = p->exit_code;
	(void)process_destroy(p);
	return ;
}
