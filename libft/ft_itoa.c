/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:04:45 by shamdani          #+#    #+#             */
/*   Updated: 2014/11/09 20:50:46 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_divdec(int n)
{
	size_t i;

	i = 1;
	if (n == -2147483648)
		return (11);
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char	*tmp;
	size_t	size;
	int		nbr;

	nbr = n;
	size = ft_divdec(n);
	if (n < 0)
	{
		nbr = -n;
		size++;
	}
	tmp = (char*)malloc(sizeof(char) * (size + 1));
	if (nbr == -2147483648)
		return (ft_strcpy(tmp, "-2147483648"));
	if (tmp)
	{
		tmp[size] = '\0';
		tmp[--size] = nbr % 10 + '0';
		while (nbr /= 10)
			tmp[--size] = nbr % 10 + '0';
		if (n < 0)
			tmp[0] = '-';
		return (tmp);
	}
	return (NULL);
}
