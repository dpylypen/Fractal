/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:54:55 by dpylypen          #+#    #+#             */
/*   Updated: 2016/12/02 18:29:06 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_put_to_str(char *str, char c)
{
	*str = c;
}

static char	*ft_str_for_num(int nb)
{
	int		len;
	char	*str;

	len = 1;
	while (nb > 9 || nb < -9)
	{
		if (nb < 0 && len == 1)
			len++;
		if (nb > 9 || nb < -9)
		{
			nb = (nb - (nb % 10)) / 10;
			len++;
		}
	}
	str = (char *)ft_memalloc(len + 1);
	if (!str)
		return (0);
	return (str);
}

static char	*ft_num_to_str(int nb, char *str)
{
	if (nb > 9 || nb < -9)
	{
		ft_num_to_str((nb - (nb % 10)) / 10, str);
		nb -= (nb - (nb % 10));
		if (nb < 0)
			nb *= -1;
	}
	if (nb < 0)
	{
		ft_put_to_str(ft_strchr(str, 0), '-');
		ft_put_to_str(ft_strchr(str, 0), (nb * -1) + '0');
	}
	else
		ft_put_to_str(ft_strchr(str, 0), (nb) + '0');
	return (str);
}

char		*ft_itoa(int nb)
{
	char *str;

	str = ft_str_for_num(nb);
	if (!str)
		return (0);
	return (ft_num_to_str(nb, str));
}
