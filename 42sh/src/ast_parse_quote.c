/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_parse_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 22:00:50 by brabo-hi          #+#    #+#             */
/*   Updated: 2018/04/15 22:15:50 by brabo-hi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parse.h"

int		parse_quote(char **word, char *str)
{
	if (!str || (*str != '\'' && *str != '"'))
		return (0);
	if (*str && *str == '\'')
		return (parse_quote_single(word, str));
	if (*str && *str == '"')
		return (parse_quote_double(word, str));
	return (0);
}

int		parse_quote_single(char **word, char *str)
{
	char	*cpy;
	int		res;
	int		i;

	res = 1;
	i = 0;
	cpy = str;
	if (!str || !*str || *str++ != '\'')
		return (0);
	if (str && *str && *str == '\'')
		return (++res);
	while (str && *str && ++res)
	{
		if (*str == '\'' && str[-1] != '\\')
			break ;
		str++;
	}
	if (!str || !*str || *str != '\'')
		return (0);
	++res;
	return (copy_str(i, res, word, cpy));
}

int		parse_quote_double(char **word, char *str)
{
	char	*cpy;
	int		res;
	int		i;

	res = 1;
	i = 0;
	str = delete_backslash_in_double_quote(str);
	cpy = str;
	if (!str || !*str || *str++ != '"')
		return (0);
	if (str && *str && *str == '"')
		return (++res);
	while (str && *str && ++res)
	{
		if (*str == '"' && str[-1] != '\\')
			break ;
		str++;
	}
	if (!str || !*str || *str != '\"')
		return (0);
	++res;
	return (copy_str(i, res, word, cpy));
}

int		copy_str(int i, int res, char **word, char *cpy)
{
	while (i++ < res)
	{
		if (!cpy)
			return (0);
		*word = ft_str_append(*word, *cpy++);
	}
	return (res);
}
