/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:34:52 by dpylypen          #+#    #+#             */
/*   Updated: 2016/12/03 18:33:13 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *last_c;

	last_c = 0;
	while (*s)
	{
		if (*s == (char)c)
			last_c = (char *)s;
		s++;
	}
	if (!c)
		return ((char*)s);
	return (last_c);
}
