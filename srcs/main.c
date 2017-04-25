/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 13:57:04 by dpylypen          #+#    #+#             */
/*   Updated: 2017/04/13 16:23:29 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	selection(char **argv)
{
	pid_t	pid;
	char	**new_argv;

	while (*(++argv))
	{
		if (**argv == 'A')
		{
			check_choise(argv);
			new_argv = ft_strsplit("* J M B G R T ", ' ');
			while (*(++new_argv))
			{
				pid = fork();
				if (pid == 0)
					start_fractol(new_argv);
			}
		}
		else
		{
			pid = fork();
			if (pid == 0)
				start_fractol(argv);
		}
	}
}

int			main(int argc, char **argv)
{
	if (argc > 1)
		selection(argv);
	else
	{
		ft_putstr("Give fractal as parameter:\nJ - julia\n");
		ft_putstr("M - mandelbrot\nB - burning ship\n");
		ft_putstr("G - glunn\nR - rabbit\nT - mandelbart\n");
		ft_putstr("A - all 6 fractals\n");
	}
	return (0);
}
