/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 14:15:40 by asarandi          #+#    #+#             */
/*   Updated: 2017/09/27 14:37:50 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreplace(char *search, char *replace, char *subject)
{
	char	*p;
	int		len;
	char	*new;

	if ((p = ft_strnstr(subject, search, ft_strlen(subject))))
	{
		len = ft_strlen(subject) - ft_strlen(search);
		len += ft_strlen(replace);
		if ((new = malloc((len + 1) * sizeof(char))) == NULL)
			return (NULL);
		ft_strncpy(new, subject, p - subject);
		ft_strlcat(new, replace, len + 1);
		ft_strlcat(new, p + ft_strlen(search), len + 1);
		return (new);
	}
	return (NULL);
}
