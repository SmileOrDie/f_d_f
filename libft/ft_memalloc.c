/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:35:55 by shamdani          #+#    #+#             */
/*   Updated: 2014/11/07 16:14:00 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*s;
	char	*t;

	s = (void*)malloc(sizeof(char) * size + 1);
	t = (char*)s;
	if (s)
	{
		while (size--)
			*t++ = 0;
		return (s);
	}
	return (NULL);
}
