/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_run_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytuz <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:13:47 by ytuz              #+#    #+#             */
/*   Updated: 2018/04/13 16:16:37 by ytuz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	free_run_numbers(t_run *run_numbers)
{
	if (run_numbers == 0)
		return ;
	if (input_head != 0)
		free(input_head);
	free(run_numbers);
}
