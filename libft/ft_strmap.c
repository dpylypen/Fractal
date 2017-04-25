/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:36:26 by dpylypen          #+#    #+#             */
/*   Updated: 2016/11/28 17:13:31 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	char	*str;

	if (s && f)
	{
		len = ft_strlen(s);
		str = ft_strnew(len);
		if (str)
			while (len--)
				str[len] = f(s[len]);
		return (str);
	}
	return (0);
}
