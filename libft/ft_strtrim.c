/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 15:43:02 by shamdani          #+#    #+#             */
/*   Updated: 2014/11/08 15:50:24 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *src)
{
	size_t		i;
	size_t		j;
	char		*tmp;

	i = 0;
	j = 0;
	if (!src)
		return (0);
	while (src[i] == ' ' || src[i] == '\n' || src[i] == '\t')
		i++;
	tmp = (char *)malloc((ft_strlen(src) - i + 1));
	if (!tmp)
		return (NULL);
	while (src[i] != '\0')
	{
		tmp[j] = src[i];
		i++;
		j++;
	}
	j--;
	while (tmp[j] == ' ' || tmp[j] == '\n' || tmp[j] == '\t')
		j--;
	tmp[j + 1] = '\0';
	return (tmp);
}
