/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_touch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 16:09:29 by shamdani          #+#    #+#             */
/*   Updated: 2015/02/15 19:47:47 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_exe_zoom(int key, t_env *e)
{
	if (key == 65451)
		ft_apply_m_to_map(e, scale(3.0 / 2.0, 3.0 / 2.0, 3.0 / 2.0));
	else if (key == 65453)
		ft_apply_m_to_map(e, scale(2.0 / 3.0, 2.0 / 3.0, 2.0 / 3.0));
}

void			ft_exe_dir(int key, t_env *e)
{
	if (key == 65361)
		ft_apply_m_to_map(e, translat(-5.0, 0.0, 0.0));
	else if (key == 65363)
		ft_apply_m_to_map(e, translat(5.0, 0.0, 0.0));
	else if (key == 65362)
		ft_apply_m_to_map(e, translat(0.0, -5.0, 0.0));
	else if (key == 65364)
		ft_apply_m_to_map(e, translat(0.0, 5.0, 0.0));
}

void			ft_exe_rot1(int key, t_env *e)
{
	if (key == 101)
		ft_apply_m_to_map(e, rotate_y(0.1));
	if (key == 114)
		ft_apply_m_to_map(e, rotate_y(-0.1));
	if (key == 100)
		ft_apply_m_to_map(e, rotate_x(0.1));
}

void			ft_exe_rot2(int key, t_env *e)
{
	if (key == 102)
		ft_apply_m_to_map(e, rotate_x(-0.1));
	if (key == 99)
		ft_apply_m_to_map(e, rotate_z(0.1));
	if (key == 118)
		ft_apply_m_to_map(e, rotate_z(-0.1));
}

int				key_hook(int key, t_env *e)
{
	if (key == 65307)
		exit(0);
	if (key == 'b')
		e->bim += 10;
	if (key == 65451 || key == 65453)
		ft_exe_zoom(key, e);
	if (key == 65361 || key == 65363 || key == 65362 || key == 65364)
		ft_exe_dir(key, e);
	if (key == 101 || key == 114 || key == 100)
		ft_exe_rot1(key, e);
	if (key == 102 || key == 99 || key == 118)
		ft_exe_rot2(key, e);
	ft_bzero(e->data, (e->height * e->sizeline) + e->width * (e->bpp / 8));
	update_img(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	black_square(e);
	help_key(e, BLACK);
	return (0);
}
