/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_condition.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 18:58:41 by ytuz              #+#    #+#             */
/*   Updated: 2018/04/13 19:23:49 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	check_if_condition(char *address)
{
	if (ft_strnequ(address, "&&", count_word_length(address)) == TRUE)
		return (TRUE);
	if (ft_strnequ(address, "||", count_word_length(address)) == TRUE)
		return (TRUE);
	return (FALSE);
}
