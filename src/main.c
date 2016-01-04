/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 14:15:42 by shamdani          #+#    #+#             */
/*   Updated: 2015/02/18 10:26:03 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector		*ft_new_t_ve(double z, double y, double i)
{
	t_vector	*vec;

	if (!(vec = (t_vector *)malloc(sizeof(t_vector))))
		return (NULL);
	vec->z = z;
	vec->y = y;
	vec->x = i;
	vec->p = 1;
	vec->color = ((int)z);
	return (vec);
}

t_vector		**ft_char_to_vec(char *str, int y, int max_x)
{
	char		**str_b;
	int			i;
	int			j;
	t_vector	**tab;

	i = 0;
	j = 0;
	str_b = ft_strsplit(str, ' ');
	if (!(tab = (t_vector **)malloc(sizeof(t_vector *) * max_x + 1)))
		return (NULL);
	while (i < max_x)
	{
		if (!str_b[j])
			tab[i] = ft_new_t_ve(0, i, y);
		else
			tab[i] = ft_new_t_ve(ft_atoi(str_b[j++]), i, y);
		i++;
	}
	tab[i] = (NULL);
	return (tab);
}

t_vector		***convert_b(char *line2, int i)
{
	int			j;
	int			max_x;
	char		**tab;
	t_vector	***conv;

	tab = (char**)malloc(sizeof(char*) * (i + 1));
	conv = (t_vector ***)malloc(sizeof(t_vector **) * (i + 1));
	if (!tab || !conv)
		return (NULL);
	i = 0;
	j = 0;
	tab = ft_strsplit(line2, '\n');
	max_x = len_num(tab[0], ' ');
	while (tab[i])
		i++;
	while (j < i)
	{
		conv[j] = ft_char_to_vec(tab[j], j, max_x);
		j++;
	}
	conv[j] = (NULL);
	return (conv);
}

t_vector		***convert(char *str, int fd, int ret, int i)
{
	char		*line;
	char		*line2;
	t_vector	***conv;

	fd = open(str, O_RDONLY);
	if (fd == (-1))
	{
		perror(str);
		return (NULL);
	}
	line2 = ft_strnew(0);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		line2 = ft_freejoin(line, line2);
		i++;
	}
	if (ret == -1)
		print_error(str, ret);
	line2 = ft_freejoin(line, line2);
	i++;
	close(fd);
	ret = empty_map(line2);
	(ret == 0) ? conv = convert_b(line2, i) : print_error(str, 0);
	return (conv);
}

int				main(int ac, char **av)
{
	t_env		*e;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
		return (0);
	if (ac == 2)
	{
		e->map = convert(av[1], 0, 0, 0);
		if (!e->map)
			return (0);
	}
	else
		print_error((NULL), 2);
	size_map(e);
	if (!(e->mlx = mlx_init()))
		print_error("env", 1);
	e->win = mlx_new_window(e->mlx, e->width, e->height, "< FDF > Project");
	e->img = mlx_new_image(e->mlx, e->width, e->height);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->sizeline, &e->endian);
	init_map(e);
	mlx_expose_hook (e->win, expose_hook, e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_loop(e->mlx);
	return (ac);
}
