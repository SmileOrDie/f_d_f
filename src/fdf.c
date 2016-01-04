/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 13:52:26 by shamdani          #+#    #+#             */
/*   Updated: 2015/02/03 17:49:22 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		check_point(t_env *e, int x, int y)
{
	if (x < e->width && y < e->height && x > 0 && y >= 0)
		put_pixel_to_img(e, x, y, e->color);
}

void		swap_integer(int *x, int *y)
{
	int		t;

	t = *x;
	*x = *y;
	*y = t;
}

void		line_b(t_point *p, t_env *e)
{
	if (p->y1 > p->y2)
	{
		swap_integer(&p->x1, &p->x2);
		swap_integer(&p->y1, &p->y2);
	}
	e->xincr = p->x2 > p->x1 ? 1 : -1;
	e->dy = p->y2 - p->y1;
	e->dx = abs(p->x2 - p->x1);
	e->d = 2 * e->dx - e->dy;
	e->aincr = 2 * (e->dx - e->dy);
	e->bincr = 2 * e->dx;
	e->x = p->x1;
	e->y = p->y1;
	check_point(e, e->x, e->y);
	while (e->y <= p->y2)
	{
		if (e->d >= 0)
		{
			e->x += e->xincr;
			e->d += e->aincr;
		}
		else
			e->d += e->bincr;
		check_point(e, e->x, e->y++);
	}
}

void		line_t(t_point *p, t_env *e)
{
	if (p->x1 > p->x2)
	{
		swap_integer(&p->x1, &p->x2);
		swap_integer(&p->y1, &p->y2);
	}
	e->yincr = p->y2 > p->y1 ? 1 : -1;
	e->dx = p->x2 - p->x1;
	e->dy = abs(p->y2 - p->y1);
	e->d = 2 * e->dy - e->dx;
	e->aincr = 2 * (e->dy - e->dx);
	e->bincr = 2 * e->dy;
	e->x = p->x1;
	e->y = p->y1;
	check_point(e, e->x, e->y);
	while (e->x <= p->x2)
	{
		if (e->d >= 0)
		{
			e->y += e->yincr;
			e->d += e->aincr;
		}
		else
			e->d += e->bincr;
		check_point(e, e->x++, e->y);
	}
}

void		line(t_point *p, t_env *e)
{
	if (abs(p->x2 - p->x1) < abs(p->y2 - p->y1))
		line_b(p, e);
	else
		line_t(p, e);
}
