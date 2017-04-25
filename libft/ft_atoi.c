/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:23:11 by dpylypen          #+#    #+#             */
/*   Updated: 2016/12/02 18:00:31 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rm_space_symb(char **str)
{
	while ((**str > 7 && **str < 14) || (**str == ' '))
		(*str)++;
}

int			ft_atoi(const char *str)
{
	int		sign;
	int		nbr;
	char	*s;

	nbr = 0;
	sign = 1;
	s = (char *)str;
	rm_space_symb(&s);
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	else if (*s == '+')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		nbr *= 10;
		nbr += *s - 48;
		s++;
	}
	return (nbr * sign);
}
