/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:14:44 by shamdani          #+#    #+#             */
/*   Updated: 2014/11/11 16:34:23 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*t;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	t = (char*)malloc (sizeof(char) * (ft_strlen(s) + 1));
	if (t)
	{
		while (s[i] != '\0')
		{
			t[i] = s[i];
			i++;
		}
		t[i] = '\0';
	}
	return (t);
}
