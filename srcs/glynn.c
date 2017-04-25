/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glynn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 13:47:33 by dpylypen          #+#    #+#             */
/*   Updated: 2017/04/13 14:29:19 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	iter(t_scene *scene, size_t *i)
{
	(*i) = -1;
	while (++(*i) < scene->max_iter)
	{
		if (fabs(scene->z_im * scene->z_im + scene->z_re * scene->z_re) > 4)
			break ;
		scene->z_re1 = scene->z_re + (scene->change_re / 10);
		scene->z_im1 = scene->z_im + (scene->change_im / 10);
		scene->z_re = sqrt((scene->z_re1 * scene->z_re1 - scene->z_im1 *
	scene->z_im1) * (scene->z_re1 * scene->z_re1 - scene->z_im1 *
	scene->z_im1)) + scene->c_re;
		scene->z_im = sqrt((2.0 * scene->z_re1 * scene->z_im1) * (2.0 *
	scene->z_re1 * scene->z_im1)) + scene->c_im;
	}
}

void		glynn(t_scene *scene)
{
	int		x;
	int		y;
	size_t	i;

	y = -1;
	while (++y < scene->height_thr)
	{
		x = -1;
		while (++x < scene->w)
		{
			scene->z_re = x * (scene->max_re - scene->min_re) /
	scene->w + scene->min_re + scene->move_x;
			scene->z_im = y * (scene->max_im - scene->min_im) /
	scene->height_thr + scene->min_im + scene->move_y;
			iter(scene, &i);
			if (scene->col_mod == 0)
				create_show_img(scene, x, y, hsv_color(scene->col_h *
	(i < scene->max_iter), scene->col_s, (i % scene->col_v) * 4));
			else
				create_show_img(scene, x, y, hsv_color(i % scene->col_h,
	scene->col_s, ((i < scene->max_iter) * scene->col_v)));
		}
	}
}
