/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 13:01:35 by dpylypen          #+#    #+#             */
/*   Updated: 2016/12/02 17:41:27 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	unsigned char *ptr_1;
	unsigned char *ptr_2;

	ptr_1 = (unsigned char *)ptr1;
	ptr_2 = (unsigned char *)ptr2;
	while (num--)
		if (*(ptr_1++) != *(ptr_2++))
			return (*(--ptr_1) - *(--ptr_2));
	return (0);
}
