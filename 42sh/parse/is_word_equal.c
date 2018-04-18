/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_word_equal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 09:51:57 by ytuz              #+#    #+#             */
/*   Updated: 2018/04/14 09:56:13 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_word_equal(char *word_head, char *reference)
{
	int	equality_result;

	equality_result = ft_strnequ(word_head, reference,
		count_word_length(word_length));
	return (equality_result);
}
