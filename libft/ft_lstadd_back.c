/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 16:28:38 by dpylypen          #+#    #+#             */
/*   Updated: 2016/12/02 18:57:39 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list *lst, t_list *new)
{
	t_list *cur;

	if (lst)
	{
		cur = ft_lstlast(lst);
		if (cur)
			cur->next = new;
	}
}
