/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 14:11:45 by dpylypen          #+#    #+#             */
/*   Updated: 2017/04/13 14:27:54 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	init_threads(t_scene *scene, t_scene *arr_scene)
{
	int i;

	i = -1;
	while (++i < scene->nb_threds)
	{
		arr_scene[i] = *scene;
		arr_scene[i].min_im = (scene->step_y * i) + scene->min_im;
		arr_scene[i].max_im = scene->max_im - (((scene->nb_threds - 1)
	- i) * scene->step_y);
		arr_scene[i].img = mlx_new_image(arr_scene[i].mlx, arr_scene[i].w,
	arr_scene[i].height_thr);
		arr_scene[i].arr = (int *)mlx_get_data_addr(arr_scene[i].img,
	&arr_scene[i].bits, &arr_scene[i].size_line, &arr_scene[i].endians);
	}
}

void		thread_create(t_scene *scene)
{
	pthread_t	arr_th_id[scene->nb_threds];
	t_scene		arr_scene[scene->nb_threds];
	int			i;
	int			status_addr;

	scene->step_y = (scene->max_im - scene->min_im) / scene->nb_threds;
	scene->height_thr = scene->h / scene->nb_threds;
	if (scene->nb_threds % 2)
		scene->height_thr++;
	status_addr = 0;
	init_threads(scene, arr_scene);
	i = -1;
	while (++i < scene->nb_threds)
		pthread_create(&(arr_th_id[i]), NULL, fractol, &(arr_scene[i]));
	i = -1;
	while (++i < scene->nb_threds)
	{
		pthread_join(arr_th_id[i], (void**)&status_addr);
		mlx_put_image_to_window(scene->mlx, scene->win, arr_scene[i].img, 0,
	arr_scene[i].height_thr * i);
		if (scene->info)
			text_info(scene, hsv_color(scene->col_h, scene->col_s,
	scene->col_v));
	}
}
