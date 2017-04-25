/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 14:11:00 by dpylypen          #+#    #+#             */
/*   Updated: 2017/04/13 16:34:21 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	text_info_2(t_scene *s, int color, char *nb_th, char *max_i)
{
	mlx_string_put(s->mlx, s->win, 37, 163,\
			color, "Threads = - and +");
	mlx_string_put(s->mlx, s->win, 37, 183,\
			color, "On/Off info = i");
	mlx_string_put(s->mlx, s->win, 37, 203,\
			color, "Color model = c");
	mlx_string_put(s->mlx, s->win, 37, 223, color, "Choose fractol\
	= 1 - 6 (NUM LOCK)");
	mlx_string_put(s->mlx, s->win, 37, 243, color, "Default = v");
	mlx_string_put(s->mlx, s->win, 37, 263, color, "Exit = exit");
	mlx_string_put(s->mlx, s->win, (s->w - 180), 35, color,\
			"Iterations:");
	mlx_string_put(s->mlx, s->win, (s->w - 180), 63, color,\
			max_i);
	mlx_string_put(s->mlx, s->win, (s->w - 180), 85, color,\
			"Threads:");
	mlx_string_put(s->mlx, s->win, (s->w - 180), 103, color,\
			nb_th);
}

void		text_info(t_scene *s, int color)
{
	static char	*nb_th = 0;
	static char	*max_i = 0;

	if (nb_th)
		free(nb_th);
	if (max_i)
		free(max_i);
	max_i = ft_itoa(s->max_iter);
	nb_th = ft_itoa(s->nb_threds);
	mlx_string_put(s->mlx, s->win, 37, 15, color, "Name: ");
	mlx_string_put(s->mlx, s->win, 120, 15, color, s->name);
	mlx_string_put(s->mlx, s->win, 37, 37, color, "Controls:");
	mlx_string_put(s->mlx, s->win, 37, 63, color, "Move = ^ v < >");
	mlx_string_put(s->mlx, s->win, 37, 83,\
			color, "Zoom = Scroll Mouse ");
	mlx_string_put(s->mlx, s->win, 37, 103,\
			color, "Change fractol = Left Mouse + Move Mose");
	mlx_string_put(s->mlx, s->win, 37, 123,\
			color, "Change color = x");
	mlx_string_put(s->mlx, s->win, 37, 143,\
			color, "Iter = + and - (NUM LOCK)");
	text_info_2(s, color, nb_th, max_i);
}
