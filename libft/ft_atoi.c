/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:51:56 by shamdani          #+#    #+#             */
/*   Updated: 2015/01/15 18:25:07 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int		res;
	int		cup;

	res = 0;
	if (str == NULL || str == 0 || str[0] == '\0')
		return (res);
	while (str[0] == '\n' || str[0] == '\v' || str[0] == '\t' || str[0] == ' '
		|| str[0] == '\f' || str[0] == '\r')
		str++;
	cup = 1;
	if (*str == '-' || *str == '+')
	{
		cup = (*str == '-') ? -cup : cup;
		str++;
	}
	while (*str && *str >= 48 && *str <= 57)
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * cup);
}
