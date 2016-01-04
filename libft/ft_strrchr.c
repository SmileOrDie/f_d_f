/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:38:31 by shamdani          #+#    #+#             */
/*   Updated: 2014/11/07 21:36:51 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *tmp;
	char *tmp2;

	tmp = (char*)s;
	tmp2 = '\0';
	while (*tmp)
	{
		if (*tmp == (char)c)
			tmp2 = tmp;
		tmp++;
	}
	if (tmp2)
		return (tmp2);
	if (c == 0)
		return (tmp);
	return (NULL);
}
