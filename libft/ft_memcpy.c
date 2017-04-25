/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 20:06:09 by dpylypen          #+#    #+#             */
/*   Updated: 2016/12/02 17:34:15 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t num)
{
	char	*des;
	char	*src;
	size_t	n;

	des = (char *)destination;
	src = (char *)source;
	n = 0;
	while (n < num)
	{
		*(des + n) = *(src + n);
		n++;
	}
	return (destination);
}
