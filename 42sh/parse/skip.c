/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:40:06 by ytuz              #+#    #+#             */
/*   Updated: 2018/04/15 14:43:20 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char			*tsh_get_next_word(char *pointer)
{
	while (*pointer && *pointer != ' ' && *pointer != ';')
		pointer++;
	if (*pointer == ';')
		return (pointer);
	pointer = tsh_skip_spaces(pointer);
	return (pointer);
}

char			*tsh_skip_spaces(char *pointer)
{
	while (*pointer == ' ')
		pointer++;
	return (pointer);
}

char			*tsh_skip_beginning(char *string_address)
{
	while (ft_strchr("\t ", *string_address) != 0)
		string_address++;
	return (string_address);
}

unsigned int	tsh_count_word_length(char *word_address)
{
	char	*word_head;

	word_head = word_address;
	while (*word_address != 0 && *count_address != ' ')
		word__address++;
	return ((unsigned int)(word_address - word_head));
}
