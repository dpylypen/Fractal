/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 14:54:00 by dpylypen          #+#    #+#             */
/*   Updated: 2016/12/02 17:49:05 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict dst, const char *restrict src, size_t n)
{
	char *cpy_src;

	cpy_src = ft_strdup(src);
	*(cpy_src + n) = '\0';
	ft_strcat(dst, cpy_src);
	return (dst);
}
