/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 18:42:14 by shamdani          #+#    #+#             */
/*   Updated: 2014/11/13 19:45:32 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strsepc(const char *s, const char c)
{
	int		count;
	char	save;

	count = 0;
	save = '\0';
	while (*s != '\0')
	{
		if (*s == c)
			save = '\0';
		if (*s != c && save == '\0')
		{
			save = c;
			count++;
		}
		s++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**p_out;
	int		pos_s;
	int		pos1;
	int		pos2;

	pos_s = 0;
	pos1 = 0;
	pos2 = 0;
	if (s == NULL)
		return (NULL);
	p_out = (char**)malloc(sizeof(char*) * (ft_strsepc(s, c) + 1));
	while (s[pos1] != '\0')
	{
		while (s[pos1] == c)
			pos1++;
		pos2 = pos1;
		while (s[pos1] != c && s[pos1] != '\0')
			pos1++;
		if (pos1 > pos2)
			p_out[pos_s++] = ft_strsub(s, pos2, (pos1 - pos2));
	}
	p_out[pos_s] = NULL;
	return (p_out);
}
