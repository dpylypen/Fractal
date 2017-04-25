/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:21:09 by dpylypen          #+#    #+#             */
/*   Updated: 2016/12/02 17:35:44 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *des, const void *src, int c, size_t num)
{
	char	*char_des;
	char	*char_src;
	size_t	n;

	char_des = (char *)des;
	char_src = (char *)src;
	n = 0;
	while (n < num)
	{
		*(char_des + n) = *(char_src + n);
		if (*(char_src + n) == c)
			return ((void *)(char_des + (n + 1)));
		n++;
	}
	return (NULL);
}
