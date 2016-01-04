/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 20:47:30 by shamdani          #+#    #+#             */
/*   Updated: 2014/11/07 23:12:08 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!n)
		return (0);
	i = 0;
	while (s1 && s2 && i < n)
	{
		if (!(*s1 || *s2) || (*s1 != *s2))
			return (*s1 - *s2);
		s1++;
		s2++;
		i++;
	}
	return (0);
}
