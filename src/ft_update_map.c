/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 17:40:32 by shamdani          #+#    #+#             */
/*   Updated: 2015/02/17 20:00:32 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point				*ft_init_pj(int i, int j, t_env *e)
{
	t_point *p;

	if (!(p = (t_point *)malloc(sizeof(t_point))))
		return (NULL);
	p->x1 = e->map[i][j - 1]->x + ((e->height / 4) + 100);
	p->y1 = e->map[i][j - 1]->y + ((e->height / 4) + 100);
	p->x2 = e->map[i][j]->x + ((e->height / 4) + 100);
	p->y2 = e->map[i][j]->y + ((e->height / 4) + 100);
	if (e->map[i][j]->color != 0 && e->map[i][j - 1]->color != 0)
		e->color = get_color(abs(e->map[i][j]->color) * 10, e->bim, 129);
	if ((e->map[i][j]->color != 0 && e->map[i][j - 1]->color == 0) ||
		(e->map[i][j]->color == 0 && e->map[i][j - 1]->color != 0))
		e->color = get_color(abs(e->map[i][j]->color) + 100, e->bim, 255);
	return (p);
}

t_point				*ft_init_pi(int i, int j, t_env *e)
{
	t_point *p;

	if (!(p = (t_point *)malloc(sizeof(t_point))))
		return (NULL);
	p->x1 = e->map[i - 1][j]->x + ((e->height / 4) + 100);
	p->y1 = e->map[i - 1][j]->y + ((e->height / 4) + 100);
	p->x2 = e->map[i][j]->x + ((e->height / 4) + 100);
	p->y2 = e->map[i][j]->y + ((e->height / 4) + 100);
	if (e->map[i][j]->color != 0 && e->map[i - 1][j]->color != 0)
		e->color = get_color(abs(e->map[i][j]->color) * 10, e->bim, 129);
	if ((e->map[i][j]->color != 0 && e->map[i - 1][j]->color == 0) ||
		(e->map[i][j]->color == 0 && e->map[i - 1][j]->color != 0))
		e->color = get_color(abs(e->map[i][j]->color) + 100, e->bim, 255);
	return (p);
}

void				update_img(t_env *e)
{
	int				i;
	int				j;

	i = -1;
	while (e->map[++i])
	{
		j = -1;
		while (e->map[i][++j])
		{
			e->color = get_color(255, 255, 255);
			if (j > 0)
				line(ft_init_pj(i, j, e), e);
			e->color = get_color(255, 255, 255);
			if (i > 0)
				line(ft_init_pi(i, j, e), e);
		}
	}
}

void				help_key(t_env *e, int color)
{
	mlx_string_put(e->mlx, e->win, 60, 30, color, "AIDE");
	mlx_string_put(e->mlx, e->win, 20, 50, color, "R = Rotation Neg Y");
	mlx_string_put(e->mlx, e->win, 20, 65, color, "E = Rotation Pos Y");
	mlx_string_put(e->mlx, e->win, 20, 80, color, "F = Rotation Neg X");
	mlx_string_put(e->mlx, e->win, 20, 95, color, "D = Rotation Pos X");
	mlx_string_put(e->mlx, e->win, 20, 110, color, "C = Rotation Neg Z");
	mlx_string_put(e->mlx, e->win, 20, 125, color, "V = Rotation Pos Z");
	mlx_string_put(e->mlx, e->win, 20, 140, color, "- = Zoom Negatif");
	mlx_string_put(e->mlx, e->win, 20, 155, color, "+ = Zoom Positif");
}

void				init_map(t_env *e)
{
	int				i;

	i = 0;
	while (++i <= 50)
		ft_apply_m_to_map(e, rotate_z(0.1));
	i = -1;
	while (i++ <= 29)
		ft_apply_m_to_map(e, rotate_z(0.1));
	while (i-- >= 0)
		ft_apply_m_to_map(e, rotate_y(-0.1));
	ft_apply_m_to_map(e, rotate_x(-0.1));
	ft_apply_m_to_map(e, scale(8.0 / 1.0, 8.0 / 1.0, 8.0 / 1.0));
}
