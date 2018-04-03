/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 02:40:42 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/02/12 00:07:23 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	t_op	*op;

	if (!(op = ft_memalloc(sizeof(t_op))))
		return (0);
	argc--;
	argv++;
	while (argc && argv[0][0] == '-' && argv[0][1] && OP(argv[0][1]))
	{
		ft_get_op(op, argv[0]);
		argv++;
		argc--;
	}
	if (!argc)
		ft_parse_args(op, ".");
	while (argc--)
		ft_parse_args(op, *argv++);
	ft_memdel((void **)&op);
	return (0);
}
