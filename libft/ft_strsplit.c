/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:24:26 by dpylypen          #+#    #+#             */
/*   Updated: 2016/12/02 18:24:31 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**ft_make_ptr_str(char const *s, char c)
{
	size_t	num;
	char	*start;
	char	**ptr_str;

	num = 1;
	start = (char *)s;
	while (*start)
	{
		if (*start == c && *(start + 1) != c && *(start + 1) != 0)
			num++;
		start++;
	}
	ptr_str = (char **)ft_memalloc(sizeof(char *) * (num + 1));
	if (!ptr_str)
		return (0);
	return (ptr_str);
}

static	void	ft_add_str(char **ptr_str, const char *start, size_t len)
{
	*ptr_str = (char *)ft_strnew(sizeof(char) * len);
	ft_memcpy(*ptr_str, start, len);
}

static size_t	ft_chr_len_chr(const char *start, char c)
{
	char *next;

	next = ft_strchr(start, c);
	if (!(next))
		next = ft_strchr(start, 0);
	return (next - start);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		len;
	const char	*start;
	char		**ptr_str;
	char		**start_ptr_str;

	if (!s)
		return (0);
	ptr_str = ft_make_ptr_str(s, c);
	start_ptr_str = ptr_str;
	if (!ptr_str)
		return (0);
	start = s;
	while (*start)
	{
		len = ft_chr_len_chr(start, c);
		if (len != 0)
			ft_add_str(ptr_str++, start, len);
		start += len;
		if (*start)
			start++;
	}
	*ptr_str = 0;
	return (start_ptr_str);
}
