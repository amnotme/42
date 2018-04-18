/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_length.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 06:46:45 by ytuz              #+#    #+#             */
/*   Updated: 2018/04/10 06:57:53 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

unsigned int	tsh_word_length(char *word)
{
	unsigned int	length;
	char			*current;

	length = 0;
	current = *(word + length);
	while (current != 0 && current != ' ' && current != ';')
	{
		length++;
		current = *(word + length);
	}
	return (length);
}
