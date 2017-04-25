/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:57:17 by dpylypen          #+#    #+#             */
/*   Updated: 2016/12/02 17:36:39 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *des, const void *src, size_t num)
{
	if (des > src)
		while (num--)
			*((char *)des + num) = *((char *)src + num);
	else
		ft_memcpy(des, src, num);
	return (des);
}
