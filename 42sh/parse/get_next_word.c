/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:23:32 by ytuz              #+#    #+#             */
/*   Updated: 2018/04/13 16:30:01 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	*get_next_word(char *address)
{
	while (*address != 0 && *address != ' ' && *address != ';')
		address++;
	address = skip_spaces(address);
	return (address);
}
