/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 20:38:27 by shamdani          #+#    #+#             */
/*   Updated: 2015/02/15 19:27:01 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_color		*get_color(int r, int g, int b)
{
	t_color	*get;

	if (!(get = (t_color *)malloc(sizeof(t_color))))
		return (NULL);
	get->r = r;
	get->g = g;
	get->b = b;
	return (get);
}

void		put_pixel_to_img(t_env *e, int x, int y, t_color *c)
{
	int		pos;

	pos = (y * e->sizeline) + x * (e->bpp / 8);
	if (e->endian)
	{
		e->data[pos] =
			mlx_get_color_value(e->mlx, c->r);
		e->data[pos + 1] =
			mlx_get_color_value(e->mlx, c->g);
		e->data[pos + 2] =
			mlx_get_color_value(e->mlx, c->b);
	}
	else
	{
		e->data[pos] =
			mlx_get_color_value(e->mlx, c->b);
		e->data[pos + 1] =
			mlx_get_color_value(e->mlx, c->g);
		e->data[pos + 2] =
			mlx_get_color_value(e->mlx, c->r);
	}
}

int			expose_hook(t_env *e)
{
	update_img(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	black_square(e);
	help_key(e, BLACK);
	return (0);
}

int			ft_screen_size(t_env *e, int x, int y)
{
	if ((x * 10) * 2 <= 1024 && (y * 10) * 2 <= 2500)
	{
		e->width = (x * 10) * 2 + 500;
		e->height = (x * 10) * 2 + 500;
	}
	else
	{
		e->width = 2560;
		e->height = 1440;
		return (0);
	}
	return (1);
}

void		size_map(t_env *e)
{
	int x;
	int y;

	x = 0;
	while (e->map[x])
	{
		y = 0;
		while (e->map[x][y])
			y++;
		x++;
	}
	e->x_max = x;
	e->y_max = y;
	ft_screen_size(e, e->x_max, e->y_max);
}
