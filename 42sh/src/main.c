/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passef <passef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 19:51:05 by asarandi          #+#    #+#             */
/*   Updated: 2018/04/18 01:10:48 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft.h"

void		ptr_null(t_shell *sh, t_ast **ptr)
{
	t_ast		*tmp;
	int			k;
	t_process	**group;

	k = 1;
	tmp = (*ptr)->parent;
	while ((tmp) && (IS_RED(tmp->name)))
	{
		tmp = tmp->parent;
		k += 1;
	}
	group = ft_memalloc(sizeof(t_process *) * (k + 1));
	k = 0;
	group[k++] = process_prepare(sh, (*ptr));
	(*ptr) = (*ptr)->parent;
	while (((*ptr)) && (IS_RED((*ptr)->name)))
	{
		group[k++] = process_prepare(sh, (*ptr)->right);
		(*ptr) = (*ptr)->parent;
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &sh->t_original);
	(void)group_process_execute(sh, group, 0, 0);
	(void)group_process_wait(group);
	(void)group_process_destroy(group);
	tcsetattr(STDIN_FILENO, TCSANOW, &sh->t_custom);
}

void		ptr_not_null(t_shell *sh, t_ast **ptr, t_process **p, int *ec)
{
	int		ec2;

	if (((*ptr)->next == NULL) &&
			((*p = process_prepare(sh, (*ptr))) != NULL))
	{
		(*ec) = process_execute(sh, *p);
		(void)process_destroy(*p);
		return ;
	}
	if (((*ptr)->type == OP_AND) && ((*ec) == 0) &&
		((*p = process_prepare(sh, (*ptr)->right)) != NULL))
	{
		ec2 = process_execute(sh, *p);
		(void)process_destroy(*p);
		if (ec2 != 0)
			(*ec) = 1;
	}
	else if (((*ptr)->type == OP_OR) && ((*ec) != 0) &&
			((*p = process_prepare(sh, (*ptr)->right)) != NULL))
	{
		ec2 = process_execute(sh, *p);
		(void)process_destroy(*p);
		if (ec2 == 0)
			(*ec) = 0;
	}
}

void		main_ptr(t_shell *sh, t_ast **ptr, t_process **p, int *ec)
{
	while ((*ptr))
	{
		if (((*ptr)->parent) && (IS_RED((*ptr)->parent->name)))
		{
			if ((*ptr)->next == NULL)
				ptr_null(sh, ptr);
		}
		else
			ptr_not_null(sh, ptr, p, ec);
		if ((*ptr) != NULL)
			(*ptr) = (*ptr)->parent;
	}
}

void		main_helper(t_shell *sh, int *ec)
{
	int			i;
	t_process	*p;
	t_ast		*ptr;
	t_ast		**ast;

	i = 0;
	if ((ft_strlen(sh->buffer) != 0) &&
			((ast = ast_create_tree(sh->buffer)) != NULL))
	{
		while (ast[i] != NULL)
		{
			ptr = ast[i];
			if (ast_is_ambiguous(ptr) == 0)
			{
				while (ptr->next)
					ptr = ptr->next;
				main_ptr(sh, &ptr, &p, ec);
			}
			i++;
		}
		sh->exit_code = *ec;
		free_trees(ast);
	}
}

int			main(int argc, char **argv, char **envp)
{
	t_shell		*sh;
	int			ec;

	ec = 0;
	sh = init_shell(argc, argv, envp);
	while (1)
	{
		sh->state = STATE_READ;
		raw_read(sh);
		if (sh->buffer == NULL)
			break ;
		main_helper(sh, &ec);
		clear_input_buffers(sh);
	}
	clean_up(sh);
	return (0);
}
