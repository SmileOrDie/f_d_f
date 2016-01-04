/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 12:38:47 by shamdani          #+#    #+#             */
/*   Updated: 2014/11/13 19:48:27 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	size_t	i;

	if (s1 != NULL && s2 != NULL)
	{
		i = ft_strlen(s1);
		tmp = (char*)malloc(sizeof(char) * ((i + ft_strlen(s2)) + 1));
		if (tmp)
		{
			ft_strcpy(tmp, (char*)s1);
			ft_strcat(tmp, (char*)s2);
		}
		return (tmp);
	}
	return (NULL);
}
