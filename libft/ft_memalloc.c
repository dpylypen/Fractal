/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 16:04:50 by dpylypen          #+#    #+#             */
/*   Updated: 2016/12/02 18:07:54 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *ptr_mem;

	ptr_mem = malloc(size);
	if (ptr_mem)
		return (ft_memset(ptr_mem, 0, size));
	return (NULL);
}
