/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbart.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 13:58:41 by dpylypen          #+#    #+#             */
/*   Updated: 2017/04/13 14:00:32 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	iter(t_scene *scene, size_t *i)
{
	(*i) = -1;
	while (++(*i) < scene->max_iter)
	{
		scene->z_re1 = scene->z_re * scene->z_re;
		scene->z_im1 = scene->z_im * scene->z_im;
		if (scene->z_re1 + scene->z_im1 > 4)
			break ;
		scene->z_im *= -1;
		scene->z_im = 2 * scene->z_re * scene->z_im + scene->c_im;
		scene->z_re = scene->z_re1 - scene->z_im1 + scene->c_re;
	}
}

static void	color(t_scene *scene, size_t i, int x, int y)
{
	if (scene->col_mod == 0)
		create_show_img(scene, x, y, hsv_color(scene->col_h *
	(i < scene->max_iter), scene->col_s, (i % scene->col_v) * 4));
	else
		create_show_img(scene, x, y, hsv_color(i % scene->col_h,
	scene->col_s, ((i < scene->max_iter) * scene->col_v)));
}

void		mandelbart(t_scene *scene)
{
	int		x;
	int		y;
	size_t	i;

	scene->re_f = (scene->max_re - scene->min_re) / (scene->w - 1);
	scene->im_f = (scene->max_im - scene->min_im) / (scene->height_thr - 1);
	y = -1;
	while (++y < scene->height_thr)
	{
		scene->c_im = scene->min_im + y * scene->im_f;
		x = -1;
		while (++x < scene->w)
		{
			scene->c_re = scene->min_re + x * scene->re_f;
			scene->z_re = scene->c_re + scene->change_re;
			scene->z_im = scene->c_im + scene->change_im;
			iter(scene, &i);
			color(scene, i, x, y);
		}
	}
}
