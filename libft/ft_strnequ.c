/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:50:49 by dpylypen          #+#    #+#             */
/*   Updated: 2016/12/02 18:15:37 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_to_lower(char c)
{
	return (ft_tolower((int)c));
}

int			ft_strnequ(char const *s1, char const *s2, size_t n)
{
	char *str1;
	char *str2;

	if (s1 && s2)
	{
		str1 = ft_strmap(s1, &ft_to_lower);
		str2 = ft_strmap(s2, &ft_to_lower);
		if (ft_strncmp(str1, str2, n) == 0)
			return (1);
	}
	return (0);
}
