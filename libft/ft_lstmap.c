/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:47:14 by dpylypen          #+#    #+#             */
/*   Updated: 2016/12/02 18:46:03 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *ret_lst;
	t_list *cur_el;

	ret_lst = 0;
	if (lst && f)
	{
		ret_lst = f(lst);
		cur_el = ret_lst;
		lst = lst->next;
		while (lst)
		{
			cur_el->next = f(lst);
			cur_el = cur_el->next;
			lst = lst->next;
		}
	}
	return (ret_lst);
}
