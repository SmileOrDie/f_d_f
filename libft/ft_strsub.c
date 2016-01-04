/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 16:03:34 by shamdani          #+#    #+#             */
/*   Updated: 2014/11/13 19:00:06 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*tmp;
	unsigned int	i;

	i = 0;
	if (s)
	{
		tmp = (char*)malloc(sizeof(char) * (len + 1));
		if (tmp)
			while (i < len)
				tmp[i++] = s[start++];
		tmp[i] = '\0';
		return (tmp);
	}
	return ((char*)s);
}
