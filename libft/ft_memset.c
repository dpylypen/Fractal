/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:24:32 by dpylypen          #+#    #+#             */
/*   Updated: 2016/12/02 17:32:06 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	char *char_ptr;

	char_ptr = (char *)ptr;
	while (num--)
		*(char_ptr + num) = (unsigned char)value;
	return (ptr);
}
