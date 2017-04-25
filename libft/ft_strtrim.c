/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:40:06 by dpylypen          #+#    #+#             */
/*   Updated: 2016/12/02 18:19:52 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	begin_rm_space(char **str)
{
	while ((**str == ' ') || (**str == '\n') || (**str == '\t'))
		(*str)++;
}

static void	end_rm_space(char **str)
{
	if (**str == '\0')
		(*str)--;
	while ((**str == ' ') || (**str == '\n') || (**str == '\t'))
		(*str)--;
}

char		*ft_strtrim(char const *s)
{
	char	*beg;
	char	*end;
	char	*str;

	if (s)
	{
		beg = (char *)s;
		begin_rm_space(&beg);
		end = beg + ft_strlen(beg);
		if (end != beg)
			end_rm_space(&end);
		str = ft_strnew(end - beg + 1);
		if (str)
			return (ft_memcpy(str, beg, end - beg + 1));
	}
	return (0);
}
