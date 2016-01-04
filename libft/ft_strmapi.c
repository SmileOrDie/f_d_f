/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 12:49:40 by shamdani          #+#    #+#             */
/*   Updated: 2014/11/07 22:40:41 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*tmp;
	unsigned int	i;

	i = 0;
	if (s && f)
	{
		tmp = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (tmp)
		{
			while (s[i] != '\0')
			{
				tmp[i] = s[i];
				tmp[i] = f(i, tmp[i]);
				i++;
			}
			return (tmp);
		}
	}
	return (NULL);
}
