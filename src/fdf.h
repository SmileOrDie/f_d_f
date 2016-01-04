/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 16:05:18 by shamdani          #+#    #+#             */
/*   Updated: 2015/02/17 18:47:35 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H
# define _FDF_H

# include <mlx.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <errno.h>
# include <math.h>
# include <stdio.h>

# define BLACK 0x000000
# define RED 0xFF0000
# define BLUE 0x0000FF
# define GREEN 0x00FF00
# define WHITE 0xFFFFFF
# define GRIS 0xA9A9A9
# define CHOCO 0xD2691E

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_vector
{
	int			color;
	double		z;
	double		y;
	double		x;
	double		p;
}				t_vector;

typedef struct	s_matrix
{
	double		a;
	double		b;
	double		c;
	double		d;
	double		e;
	double		f;
	double		g;
	double		h;
	double		i;
	double		j;
	double		k;
	double		l;
	double		m;
	double		n;
	double		o;
	double		p;
}				t_matrix;

typedef struct	s_point
{
	int			x1;
	int			y1;
	int			x2;
	int			y2;
}				t_point;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	t_vector	***map;
	int			bpp;
	int			sizeline;
	int			endian;
	int			y;
	int			x;
	int			y_max;
	int			x_max;
	int			d;
	int			dx;
	int			dy;
	int			bim;
	int			aincr;
	int			bincr;
	int			xincr;
	int			yincr;
	int			width;
	int			height;
	t_color		*color;
}				t_env;

void			line(t_point *p, t_env *e);
void			swap_integer(int *x, int *y);
int				expose_hook(t_env *e);
int				key_hook(int keycode, t_env *e);
t_matrix		*scale(double a, double f, double k);
t_matrix		*translat(double d, double h, double l);
t_matrix		*rotate_y(double delta);
t_matrix		*rotate_x(double delta);
t_matrix		*rotate_z(double delta);
void			ft_apply_m_to_map(t_env *e, t_matrix *m);
t_vector		*ft_m_x_v(t_matrix *m, t_vector *o);
void			init_mat(t_matrix *m);
void			init_map(t_env *e);
void			update_img(t_env *e);
void			help_key(t_env *e, int color);
void			black_square(t_env *e);
int				expose_hook(t_env *e);
void			put_pixel_to_img(t_env *e, int x, int y, t_color *c);
t_color			*get_color(int r, int g, int b);
void			ft_clearimg(char *data, size_t xmax, size_t ymax);
char			*ft_freejoin(char *b, char *c);
int				ft_screen_size(t_env *e, int x, int y);
void			size_map(t_env *e);
void			print_error(char *c, int i);
int				empty_map(char *str);

#endif
