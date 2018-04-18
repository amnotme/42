/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 05:13:13 by asarandi          #+#    #+#             */
/*   Updated: 2018/04/11 10:55:50 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft.h"

int	unmatched_quote_error(t_av *av, char quote)
{
	cleanup_av_buffers(av);
	ft_printf(STDERR_FILENO, UNMATCHED_QUOTE, quote);
	return (0);
}

int	handle_strong_quote(t_av *av, int *i, int *k)
{
	char	*in;
	char	*out;

	in = av->in;
	out = av->out;
	(*i)++;
	if ((ft_strchr(&in[*i], STRONG_QUOTE)) == NULL)
		return (unmatched_quote_error(av, STRONG_QUOTE));
	while (in[*i] != STRONG_QUOTE)
		out[(*k)++] = in[(*i)++];
	(*i)++;
	return (2);
}

int	handle_dollar_sign(t_av *av, t_shell *sh, int *i, int *k)
{
	int		z;

	(*i)++;
	z = 0;
	while (ft_isalnum2(av->in[*i + z]))
		z++;
	ft_strncpy(av->key, &(av->in[*i]), z);
	av->key[z] = 0;
	av->val = kv_array_get_key_value(sh->envp, av->key);
	if (av->val == NULL)
		ft_printf(STDERR_FILENO, UNDEFINED_VARIABLE, av->key);
	else
	{
		z = 0;
		while (av->val[z])
			av->out[(*k)++] = av->val[z++];
	}
	(*i) += ft_strlen(av->key);
	return (1);
}

int	handle_weak_quote(t_av *av, t_shell *sh, int *i, int *k)
{
	char	*in;
	char	*out;

	in = av->in;
	out = av->out;
	(*i)++;
	if ((ft_strchr(&av->in[*i], WEAK_QUOTE)) == NULL)
		return (unmatched_quote_error(av, WEAK_QUOTE));
	while (av->in[*i] != WEAK_QUOTE)
	{
		if ((av->in[*i] == DOLLAR_SIGN) && (ft_isalpha(av->in[*i + 1])))
			(void)handle_dollar_sign(av, sh, i, k);
		else
			out[(*k)++] = in[(*i)++];
	}
	(*i)++;
	return (2);
}
