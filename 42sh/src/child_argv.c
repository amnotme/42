/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 05:57:11 by asarandi          #+#    #+#             */
/*   Updated: 2018/04/15 14:37:09 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft.h"

void	cleanup_av_buffers(t_av *av)
{
	if (av->out != NULL)
		free(av->out);
	if (av->key != NULL)
		free(av->key);
	free(av);
	return ;
}

void	add_string_to_child_argv(t_av *av, char *str, int *k)
{
	char **old_array;
	char *new_string;

	if ((str == NULL) || (str[0] == 0))
		return ;
	str[*k] = 0;
	*k = 0;
	old_array = av->argv;
	new_string = ft_strdup(str);
	av->argv = add_element_to_char_array(av->argv, new_string);
	destroy_char_array(old_array);
	return ;
}

int		is_end_of_argument(char c)
{
	if (ft_isspace(c))
		return (1);
	if (c == 0)
		return (1);
	return (0);
}

int		mini_parse(t_shell *sh, t_av *av, int *i, int *k)
{
	int	r;

	r = 1;
	if (av->in[*i] == STRONG_QUOTE)
		r = handle_strong_quote(av, i, k);
	else if (av->in[*i] == WEAK_QUOTE)
		r = handle_weak_quote(av, sh, i, k);
	else if ((av->in[*i] == DOLLAR_SIGN) && (ft_isalpha(av->in[*i + 1])))
		r = handle_dollar_sign(av, sh, i, k);
	else if ((av->in[*i] == BACKSLASH) && ((*i)++))
		av->out[(*k)++] = av->in[(*i)++];
	else
		av->out[(*k)++] = av->in[(*i)++];
	if ((r > 0) && (is_end_of_argument(av->in[*i])))
		add_string_to_child_argv(av, av->out, k);
	return (r);
}

char	**build_child_argv_list(t_shell *sh, char *cmd)
{
	char	**result;
	t_av	*av;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if ((av = init_av_buffers(cmd)) == NULL)
		return (NULL);
	while ((av->in[i]) && (ft_isspace(av->in[i])))
		i++;
	while (av->in[i])
	{
		if ((mini_parse(sh, av, &i, &k)) == 0)
			return (NULL);
		while ((av->in[i]) && (ft_isspace(av->in[i])))
			i++;
	}
	result = av->argv;
	cleanup_av_buffers(av);
	return (result);
}
