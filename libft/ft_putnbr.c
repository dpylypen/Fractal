/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:46:42 by dpylypen          #+#    #+#             */
/*   Updated: 2016/12/02 18:34:38 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n > 9 || n < -9)
	{
		ft_putnbr((n - (n % 10)) / 10);
		n -= (n - (n % 10));
		if (n < 0)
			n *= -1;
	}
	if (n < 0)
	{
		ft_putchar('-');
		ft_putchar((n * -1) + '0');
	}
	else
		ft_putchar((n) + '0');
}
