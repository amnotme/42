/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_conditional.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 10:04:57 by ytuz              #+#    #+#             */
/*   Updated: 2018/04/14 10:10:03 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	is_conditional(char *word_head)
{
	if (is_word_equal(word_head, "&&") == TRUE ||
		is_word_equal(word_head, "||") == TRUE)
		return (TRUE);
	return (FALSE);
}
