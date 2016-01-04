/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 15:41:54 by shamdani          #+#    #+#             */
/*   Updated: 2015/01/07 19:19:34 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix		*scale(double a, double f, double k)
{
	t_matrix	*mat;

	if (!(mat = (t_matrix *)malloc(sizeof(t_matrix))))
		return (NULL);
	init_mat(mat);
	mat->a = a;
	mat->f = f;
	mat->k = k;
	mat->p = 1;
	return (mat);
}

t_matrix		*translat(double d, double h, double l)
{
	t_matrix	*mat;

	if (!(mat = (t_matrix *)malloc(sizeof(t_matrix))))
		return (NULL);
	init_mat(mat);
	mat->d = d;
	mat->h = h;
	mat->l = l;
	mat->a = 1;
	mat->f = 1;
	mat->k = 1;
	mat->p = 1;
	return (mat);
}

t_matrix		*rotate_y(double delta)
{
	t_matrix	*mat;

	if (!(mat = (t_matrix *)malloc(sizeof(t_matrix))))
		return (NULL);
	ft_memalloc(sizeof(mat));
	mat->a = cos(delta);
	mat->c = sin(delta);
	mat->f = 1;
	mat->i = -sin(delta);
	mat->k = cos(delta);
	mat->p = 1;
	return (mat);
}

t_matrix		*rotate_x(double delta)
{
	t_matrix	*mat;

	if (!(mat = (t_matrix *)malloc(sizeof(t_matrix))))
		return (NULL);
	ft_memalloc(sizeof(mat));
	mat->a = 1;
	mat->f = cos(delta);
	mat->g = -sin(delta);
	mat->j = sin(delta);
	mat->k = cos(delta);
	mat->p = 1;
	return (mat);
}

t_matrix		*rotate_z(double delta)
{
	t_matrix	*mat;

	if (!(mat = (t_matrix *)malloc(sizeof(t_matrix))))
		return (NULL);
	init_mat(mat);
	mat->a = cos(delta);
	mat->b = -sin(delta);
	mat->e = sin(delta);
	mat->f = cos(delta);
	mat->k = 1;
	mat->p = 1;
	return (mat);
}
