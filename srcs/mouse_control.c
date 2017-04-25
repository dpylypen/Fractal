/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 14:03:52 by dpylypen          #+#    #+#             */
/*   Updated: 2017/04/13 14:07:15 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	zoom_to_mouse(t_scene *p, double x, double y)
{
	double	xy[2];

	xy[0] = x / p->w * (p->max_re - p->min_re) + p->min_re;
	xy[1] = y / p->h * (p->max_im - p->min_im) + p->min_im;
	p->min_re = p->min_re * p->zoom + (xy[0] * (1 - p->zoom));
	p->max_re = p->max_re * p->zoom + (xy[0] * (1 - p->zoom));
	p->min_im = p->min_im * p->zoom + (xy[1] * (1 - p->zoom));
	p->max_im = p->max_im * p->zoom + (xy[1] * (1 - p->zoom));
}

int		mouse_hook(int key, int x, int y, void *param)
{
	t_scene *scene;

	scene = (t_scene*)param;
	if (key == 1 && !scene->is_presed_1)
		scene->is_presed_1 = 1;
	if (key == 4)
	{
		scene->zoom = 0.9;
		if (scene->z_cof < 332)
		{
			zoom_to_mouse(scene, x, y);
			scene->z_cof++;
		}
	}
	if (key == 5)
	{
		scene->zoom = 1.1;
		zoom_to_mouse(scene, x, y);
		if (scene->z_cof > 1)
			scene->z_cof--;
	}
	thread_create(scene);
	return (0);
}

int		mouse_free(int key, int x, int y, void *param)
{
	t_scene *scene;

	scene = (t_scene*)param;
	if (key == 1 && scene->is_presed_1 && x && y)
		scene->is_presed_1 = 0;
	return (0);
}

int		mouse_move(int x, int y, void *param)
{
	t_scene *scene;

	scene = (t_scene*)param;
	if (scene->is_presed_1 && x > 0 && x < scene->w && y > 0 && y < scene->h)
	{
		if (scene->fract_id == 0)
		{
			scene->c_re = -(float)x / scene->w;
			scene->c_im = -(float)y / scene->h;
		}
		else
		{
			scene->change_re = (float)x / scene->w * 2;
			scene->change_im = (float)y / scene->h * 2;
		}
		thread_create(scene);
	}
	return (0);
}
