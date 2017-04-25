/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 11:41:35 by dpylypen          #+#    #+#             */
/*   Updated: 2016/12/02 17:38:29 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	unsigned char	*pos;
	size_t			n;

	pos = (unsigned char *)ptr;
	n = 0;
	while (n < num)
	{
		if (pos[n] == (unsigned char)value)
			return ((void *)(pos + n));
		n++;
	}
	return (NULL);
}
