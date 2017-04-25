/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 13:46:47 by dpylypen          #+#    #+#             */
/*   Updated: 2017/04/13 14:15:45 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_scene		def_init(char **argv)
{
	t_scene scene;

	get_fract_id(&scene, argv);
	scene.mlx = mlx_init();
	scene.w = 800;
	scene.h = 600;
	scene.win = mlx_new_window(scene.mlx, scene.w, scene.h, "Fractol");
	scene.zoom = 1;
	scene.move_x = 0;
	scene.move_y = 0;
	scene.c_re = -0.7;
	scene.c_im = 0.27015;
	scene.col_h = 256;
	scene.col_s = 255;
	scene.col_v = 255;
	scene.max_iter = 30;
	scene.nb_threds = 7;
	scene.change_re = 0;
	scene.change_im = 0;
	scene.is_presed_1 = 0;
	scene.col_mod = 0;
	scene.info = 1;
	scene.z_cof = 1;
	return (scene);
}

static void	fract_init_2(t_scene *scene)
{
	if (scene->fract_id == 2)
	{
		scene->name = "Fractol burningship";
		scene->min_re = -2;
		scene->max_re = 1;
		scene->min_im = -1.8;
		scene->max_im = 1;
	}
	if (scene->fract_id == 3)
	{
		scene->name = "Fractol glynn";
		scene->min_re = -1.54;
		scene->max_re = 1.54;
		scene->min_im = -1.17;
		scene->max_im = 1.3;
		scene->c_re = 0.291;
		scene->c_im = 0.006;
	}
}

static void	fract_init_3(t_scene *scene)
{
	if (scene->fract_id == 4)
	{
		scene->name = "Fractol rabbit";
		scene->min_re = -1.6;
		scene->max_re = 1.6;
		scene->min_im = -1.6;
		scene->max_im = 1.6;
		scene->c_re = -0.12;
		scene->c_im = 0.75;
	}
	if (scene->fract_id == 5)
	{
		scene->name = "Fractol mandelbart";
		scene->min_re = -2;
		scene->max_re = 1.6;
		scene->min_im = -1.6;
		scene->max_im = 1.6;
	}
}

void		fract_init(t_scene *scene)
{
	scene->z_cof = 0;
	if (scene->fract_id == 0)
	{
		scene->name = "Fractol julia";
		scene->min_re = -1.6;
		scene->max_re = 1.6;
		scene->min_im = -1.6;
		scene->max_im = 1.6;
		scene->c_re = -0.7;
		scene->c_im = 0.27015;
	}
	if (scene->fract_id == 1)
	{
		scene->name = "Fractol mandelbrot";
		scene->min_re = -2;
		scene->max_re = 1;
		scene->min_im = -1.2;
		scene->max_im = 1.2;
	}
	fract_init_2(scene);
	fract_init_3(scene);
}

void		*fractol(void *p)
{
	t_scene *scene;

	scene = (t_scene *)p;
	if (scene->fract_id == 0)
		julia(scene);
	else if (scene->fract_id == 1)
		mandelbrot(scene);
	else if (scene->fract_id == 2)
		burning_ship(scene);
	else if (scene->fract_id == 3)
		glynn(scene);
	else if (scene->fract_id == 4)
		rabbit(scene);
	else if (scene->fract_id == 5)
		mandelbart(scene);
	else
		ft_putstr("Error_id\n");
	return (NULL);
}
