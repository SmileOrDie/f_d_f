/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabc_to_tabi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 23:09:47 by shamdani          #+#    #+#             */
/*   Updated: 2015/02/03 11:42:30 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			len_num(char *t, char c)
{
	int		i;
	int		j;
	int		len;

	i = -1;
	while (t[++i])
	{
		if (t[i] != c && j == 0)
		{
			j = 1;
			len++;
		}
		if (t[i] == c)
			j = 0;
	}
	return (len);
}

void		ft_free_tab(char ***tab)
{
	int		i;

	i = 0;
	while ((*tab)[i])
	{
		free((*tab)[i]);
		i++;
	}
	free(*tab);
	*tab = NULL;
}

int			*convert_t(char *t, char c, t_tabi *tabi)
{
	int		*tab;
	char	**c_b;
	int		i;

	i = 0;
	c_b = ft_strsplit(t, c);
	if (!(tab = (int *)malloc((sizeof(int) * len_num(t, c) + 1))))
		return (NULL);
	while (c_b[i])
	{
		tab[i] = ft_atoi(c_b[i]);
		i++;
	}
	ft_free_tab(&c_b);
	tabi->x = i;
	return (tab);
}

t_tabi		*tabc_to_tabi(char **tabc, char c)
{
	int		i;
	t_tabi	*tabi;

	i = 0;
	if (!(tabi = (t_tabi *)malloc(sizeof(t_tabi))))
		return (NULL);
	while (tabc[i])
		i++;
	tabi->y = i;
	if (!(tabi->map = (int **)malloc(sizeof(int *) * i)))
		return (NULL);
	i = -1;
	while (tabc[++i])
		tabi->map[i] = convert_t(tabc[i], c, tabi);
	return (tabi);
}
