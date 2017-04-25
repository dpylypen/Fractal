/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 13:52:34 by dpylypen          #+#    #+#             */
/*   Updated: 2017/04/13 13:56:23 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	control_unit_1(int key, t_scene *scene)
{
	if (key == 53)
		exit(0);
	if (key == 8)
	{
		if (scene->col_mod == 0)
		{
			scene->col_mod++;
			scene->col_h = 256;
		}
		else
			scene->col_mod--;
	}
	if (key == 7)
	{
		if (scene->col_mod == 0)
		{
			if (scene->col_h >= 300)
				scene->col_h = 0;
			else
				scene->col_h += 60;
		}
	}
}

static void	control_unit_2(int key, t_scene *scene)
{
	if (key == 9)
		fract_init(scene);
	if (key == 34)
	{
		if (scene->info)
			scene->info--;
		else
			scene->info++;
	}
	if (key == 27)
	{
		if (scene->nb_threds > 1)
			scene->nb_threds--;
	}
	if (key == 24)
	{
		if (scene->nb_threds != 12)
			scene->nb_threds++;
	}
	if (key == 86)
	{
		scene->fract_id = 3;
		fract_init(scene);
	}
}

static void	control_unit_3(int key, t_scene *scene)
{
	if (key == 87)
	{
		scene->fract_id = 4;
		fract_init(scene);
	}
	if (key == 88)
	{
		scene->fract_id = 5;
		fract_init(scene);
	}
	if (key == 69)
		scene->max_iter += 20;
	if (key == 78)
		if (scene->max_iter >= 10)
			scene->max_iter -= 10;
	if (key == 83)
	{
		scene->fract_id = 0;
		fract_init(scene);
	}
	if (key == 84)
	{
		scene->fract_id = 1;
		fract_init(scene);
	}
}

static void	control_unit_4(int key, t_scene *scene)
{
	if (key == 85)
	{
		scene->fract_id = 2;
		fract_init(scene);
	}
	if (key == 126)
	{
		scene->max_im += scene->im_factor * 5;
		scene->min_im += scene->im_factor * 5;
	}
	if (key == 125)
	{
		scene->max_im -= scene->im_factor * 5;
		scene->min_im -= scene->im_factor * 5;
	}
	if (key == 123)
	{
		scene->max_re += scene->re_factor * 5;
		scene->min_re += scene->re_factor * 5;
	}
	if (key == 124)
	{
		scene->max_re -= scene->re_factor * 5;
		scene->min_re -= scene->re_factor * 5;
	}
}

int			key_press(int key, void *param)
{
	t_scene *scene;

	scene = (t_scene *)param;
	scene->re_factor = (scene->max_re - scene->min_re) / (scene->w - 1);
	scene->im_factor = (scene->max_im - scene->min_im) / (scene->h - 1);
	control_unit_1(key, scene);
	control_unit_2(key, scene);
	control_unit_3(key, scene);
	control_unit_4(key, scene);
	thread_create(scene);
	return (0);
}
