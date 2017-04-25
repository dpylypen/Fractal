/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 13:26:40 by dpylypen          #+#    #+#             */
/*   Updated: 2017/04/13 16:23:00 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "pthread.h"
# include "../libft/libft.h"

typedef struct	s_scene
{
	void		*mlx;
	void		*win;
	void		*img;
	int			endians;
	int			bits;
	int			size_line;
	int			*arr;
	double		zoom;
	double		move_y;
	double		move_x;
	int			w;
	int			h;
	double		step_y;
	int			height_thr;
	double		c_re;
	double		c_im;
	double		min_re;
	double		min_re_s;
	double		max_re;
	double		max_re_s;
	double		min_im;
	double		min_im_s;
	double		max_im;
	double		max_im_s;
	double		z_re;
	double		z_im;
	double		z_re1;
	double		z_im1;
	double		re_f;
	double		im_f;
	double		re_factor;
	double		im_factor;
	int			col_h;
	int			col_s;
	int			col_v;
	int			col_mod;
	size_t		max_iter;
	int			fract_id;
	int			is_presed_1;
	int			nb_threds;
	double		change_re;
	double		change_im;
	int			info;
	char		*name;
	int			z_cof;
}				t_scene;

typedef struct	s_hsv
{
	float		d1;
	int			h1;
	float		f;
	float		p;
	float		q;
	float		t;
}				t_hsv;

t_scene			def_init(char **argv);
void			julia(t_scene *scene);
void			mandelbrot(t_scene *scene);
void			burning_ship(t_scene *scene);
void			glynn(t_scene *scene);
void			rabbit(t_scene *scene);
void			mandelbart(t_scene *scene);
void			fract_init(t_scene *scene);
void			get_fract_id(t_scene *scene, char **argv);
void			start_fractol(char **argv);
int				hsv_color(int h, int s, int v);
void			create_show_img(t_scene *s, int x, int y, int rgb);
void			*fractol(void *p);
void			thread_create(t_scene *scene);
int				key_press(int key, void *param);
int				mouse_hook(int key, int x, int y, void *param);
int				mouse_free(int key, int x, int y, void *param);
int				mouse_move(int x, int y, void *param);
void			text_info(t_scene *s, int color);
int				key_press(int key, void *param);
void			check_choise(char **argv);
#endif
