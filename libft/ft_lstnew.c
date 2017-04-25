/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:07:08 by dpylypen          #+#    #+#             */
/*   Updated: 2016/12/03 14:04:54 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;
	void	*tmp;

	list = (t_list *)ft_memalloc(sizeof(t_list));
	if (list)
	{
		if (ft_memalloc(content_size) && content_size && content)
		{
			tmp = ft_memalloc(content_size);
			list->content = ft_memcpy(tmp, content, content_size);
			list->content_size = content_size;
		}
		else
		{
			list->content = NULL;
			list->content_size = 0;
		}
	}
	return (list);
}
