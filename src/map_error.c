/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:04:30 by shamdani          #+#    #+#             */
/*   Updated: 2015/02/17 19:38:10 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_error(char *c, int i)
{
	if (i == 0)
	{
		ft_putstr_fd(c, 2);
		ft_putstr_fd(" : empty file! try again whith a good one\n", 2);
	}
	else if (i == 2)
		ft_putstr_fd("only one argument\n", 2);
	else if (i == -1)
		ft_putstr_fd("invalid argument\n", 2);
	else
	{
		ft_putstr_fd(c, 2);
		ft_putstr_fd(" -> is corrupted or strange!\n", 2);
	}
	exit(0);
}

int		empty_map(char *str)
{
	if (!str[0])
		return (1);
	else
		return (0);
}
