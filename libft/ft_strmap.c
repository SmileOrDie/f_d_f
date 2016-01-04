/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 12:56:07 by shamdani          #+#    #+#             */
/*   Updated: 2014/11/07 22:36:36 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char		*tmp;
	size_t		i;

	i = 0;
	if (s && f)
	{
		tmp = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (tmp)
		{
			while (s[i] != '\0')
			{
				tmp[i] = s[i];
				tmp[i] = f(tmp[i]);
				i++;
			}
			tmp[i] = '\0';
			return (tmp);
		}
	}
	return (NULL);
}
