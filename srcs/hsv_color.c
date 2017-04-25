/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsv_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 13:34:15 by dpylypen          #+#    #+#             */
/*   Updated: 2017/04/13 13:37:15 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	hsv_color_2(t_hsv t, int v, int *rgb)
{
	if (t.h1 == 2)
	{
		rgb[0] = floorf(t.p);
		rgb[1] = floorf(v);
		rgb[2] = floorf(t.t);
	}
	if (t.h1 == 3)
	{
		rgb[0] = floorf(t.p);
		rgb[1] = floorf(t.q);
		rgb[2] = floorf(v);
	}
	if (t.h1 == 4)
	{
		rgb[0] = floorf(t.t);
		rgb[1] = floorf(t.p);
		rgb[2] = floorf(v);
	}
	if (t.h1 == 5)
	{
		rgb[0] = floorf(v);
		rgb[1] = floorf(t.p);
		rgb[2] = floorf(t.q);
	}
}

int			hsv_color(int h, int s, int v)
{
	int		rgb[3];
	t_hsv	t;

	t.d1 = s / 255;
	t.h1 = h /= 60.0;
	t.f = (h - t.h1);
	t.p = v * (1 - t.d1);
	t.q = v * (1 - (t.f * t.d1));
	t.t = v * (1 - (1 - t.f) * t.d1);
	if (t.h1 == 0)
	{
		rgb[0] = floorf(v);
		rgb[1] = floorf(t.t);
		rgb[2] = floorf(t.p);
	}
	if (t.h1 == 1)
	{
		rgb[0] = floorf(t.q);
		rgb[1] = floorf(v);
		rgb[2] = floorf(t.p);
	}
	hsv_color_2(t, v, rgb);
	return ((rgb[0] << 16) + (rgb[1] << 8) + (rgb[2]));
}
