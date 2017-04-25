/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_fractol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 14:09:14 by dpylypen          #+#    #+#             */
/*   Updated: 2017/04/13 17:30:43 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		check_choise(char **argv)
{
	if (*(*argv + 1) != '\0')
	{
		ft_putstr("\n\033[22;31mError_choose!\033[0m\n");
		ft_putstr("Give fractal as parameter:\nJ - julia\n");
		ft_putstr("M - mandelbrot\nB - burning ship\n");
		ft_putstr("G - glunn\nR - rabbit\nT - mandelbart\n");
		ft_putstr("A - all 6 fractals\n");
		exit(EXIT_FAILURE);
	}
}

void		get_fract_id(t_scene *scene, char **argv)
{
	check_choise(argv);
	if (**argv == 'J')
		scene->fract_id = 0;
	else if (**argv == 'M')
		scene->fract_id = 1;
	else if (**argv == 'B')
		scene->fract_id = 2;
	else if (**argv == 'G')
		scene->fract_id = 3;
	else if (**argv == 'R')
		scene->fract_id = 4;
	else if (**argv == 'T')
		scene->fract_id = 5;
	else
	{
		ft_putstr("\n\033[22;31mError_choose!\033[0m\n");
		ft_putstr("Give fractal as parameter:\nJ - julia\n");
		ft_putstr("M - mandelbrot\nB - burning ship\n");
		ft_putstr("G - glunn\nR - rabbit\nT - mandelbart\n");
		ft_putstr("A - all 6 fractals\n");
		exit(EXIT_FAILURE);
	}
}

static int	x(void)
{
	exit(0);
}

void		start_fractol(char **argv)
{
	t_scene scene;

	scene = def_init(argv);
	fract_init(&scene);
	thread_create(&scene);
	mlx_mouse_hook(scene.win, mouse_hook, &scene);
	mlx_hook(scene.win, 5, 0, mouse_free, &scene);
	mlx_hook(scene.win, 2, 0, key_press, &scene);
	mlx_hook(scene.win, 6, 5, mouse_move, &scene);
	mlx_hook(scene.win, 17, 0, x, &scene);
	mlx_loop(scene.mlx);
}
