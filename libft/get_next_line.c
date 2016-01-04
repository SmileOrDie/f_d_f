/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 18:15:15 by shamdani          #+#    #+#             */
/*   Updated: 2015/02/03 19:23:19 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_get_line(int ret, char *buf, char **tmp)
{
	char		*tmp2;

	buf[ret] = '\0';
	tmp2 = *tmp;
	*tmp = ft_strjoin(tmp2, buf);
	ft_strdel(&tmp2);
}

void			ft_get_bis(char **line, char **tmp)
{
	char		*tmp2;
	size_t		len;

	len = ft_strchr(*tmp, '\n') - *tmp;
	*line = ft_strsub(*tmp, 0, len);
	tmp2 = *tmp;
	*tmp = ft_strdup(ft_strchr(*tmp, '\n') + 1);
	ft_strdel(&tmp2);
}

int				get_next_line(int const fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			ret;
	static char	*tmp;

	if (!tmp)
		tmp = ft_strnew(0);
	if (!line)
		return (-1);
	ret = 0;
	while (!(ft_strchr(tmp, '\n')) && (ret = read(fd, buf, BUFF_SIZE)) > 0)
		ft_get_line(ret, buf, &tmp);
	if (ret == -1)
		return (-1);
	if (ret == 0 && !(ft_strchr(tmp, '\n')))
	{
		*line = tmp;
		tmp = NULL;
		return (0);
	}
	ft_get_bis(line, &tmp);
	return (1);
}
