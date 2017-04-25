/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:59:57 by dpylypen          #+#    #+#             */
/*   Updated: 2016/12/02 17:54:57 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char *ptr_little;
	char *ptr_big;

	if (*little == '\n' || *little == '\0')
		return ((char *)big);
	while (*big)
	{
		ptr_little = (char *)little;
		if (*big == *ptr_little)
		{
			ptr_big = (char *)big;
			while (*ptr_big == *ptr_little || !(*ptr_little))
			{
				if (!(*ptr_little))
					return ((char *)big);
				ptr_big++;
				ptr_little++;
			}
		}
		big++;
	}
	return (0);
}
