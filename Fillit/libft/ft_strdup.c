/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <gmalpart@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 07:36:21 by gmalpart          #+#    #+#             */
/*   Updated: 2017/10/21 07:36:22 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*temp;

	if (!(temp = malloc((sizeof(char) * ft_strlen(s1)) + 1)))
		return (NULL);
	ft_strcpy(temp, s1);
	return (temp);
}
