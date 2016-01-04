/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 16:53:42 by shamdani          #+#    #+#             */
/*   Updated: 2015/02/03 18:11:09 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			init_mat(t_matrix *m)
{
	m->a = 0;
	m->b = 0;
	m->c = 0;
	m->d = 0;
	m->e = 0;
	m->f = 0;
	m->g = 0;
	m->h = 0;
	m->i = 0;
	m->j = 0;
	m->k = 0;
	m->l = 0;
	m->m = 0;
	m->n = 0;
	m->o = 0;
	m->p = 0;
}

t_vector		*ft_m_x_v(t_matrix *m, t_vector *o)
{
	t_vector	*v;

	v = (t_vector *)malloc(sizeof(t_vector));
	v->x = m->a * o->x + m->b * o->y + m->c * o->z + m->d * o->p;
	v->y = m->e * o->x + m->f * o->y + m->g * o->z + m->h * o->p;
	v->z = m->i * o->x + m->j * o->y + m->k * o->z + m->l * o->p;
	v->p = m->m * o->x + m->n * o->y + m->o * o->z + m->p * o->p;
	v->color = o->color;
	return (v);
}

void			ft_apply_m_to_map(t_env *e, t_matrix *m)
{
	int			i;
	int			j;

	i = 0;
	while (e->map[i])
	{
		j = 0;
		while (e->map[i][j])
		{
			e->map[i][j] = ft_m_x_v(m, e->map[i][j]);
			j++;
		}
		i++;
	}
}

void			black_square(t_env *e)
{
	int i;
	int j;

	i = 0;
	while (i < 175)
	{
		j = 0;
		while (j < 150)
		{
			if ((j > 140 || i > 165) || (j < 10 || i < 10))
				mlx_pixel_put(e->mlx, e->win, j, i, CHOCO);
			else
				mlx_pixel_put(e->mlx, e->win, j, i, GRIS);
			j++;
		}
		i++;
	}
}

char			*ft_freejoin(char *line, char *line2)
{
	char		*tmp;

	if (line[0] != '\0')
	{
		tmp = ft_strjoin(line, "\n");
		free(line);
		line = tmp;
		tmp = ft_strjoin(line2, line);
		free(line2);
		line2 = tmp;
	}
	return (line2);
}
