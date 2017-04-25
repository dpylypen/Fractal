/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:11:01 by dpylypen          #+#    #+#             */
/*   Updated: 2016/12/02 19:13:49 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t l)
{
	char *ptr;

	ptr = ft_strstr(big, little);
	if ((ptr - big) + ft_strlen(little) > l)
		return (0);
	return (ptr);
}
