/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_word_length.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:00:51 by ytuz              #+#    #+#             */
/*   Updated: 2018/04/13 18:58:35 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	count_word_length(char *word_head)
{
	char	*word_end;

	word_end = word_head;
	while (*word_end != 0 && *word_end != ' ' && *word_end != ';')
		word_end++;
	return ((unsigned int)(word_end - word_head));
}
