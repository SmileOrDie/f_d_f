/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:03:56 by shamdani          #+#    #+#             */
/*   Updated: 2014/11/07 23:17:26 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strret(size_t k, size_t i, size_t j, const char *s1)
{
	while (k++ < (int)i - j)
		s1++;
	return ((char*)s1);
}

char			*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;
	size_t		k;

	k = 0;
	i = 0;
	j = 0;
	if (s2[i] == '\0')
		return ((char*)s1);
	while (s1[i] != '\0')
	{
		if (s1[i] == s2[j] && i < n)
			j++;
		else if (j > 0)
		{
			i--;
			j = 0;
		}
		i++;
		if (s2[j] == '\0')
			return (ft_strret(k, i, j, s1));
	}
	return (NULL);
}
