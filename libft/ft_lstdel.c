/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 13:59:30 by dpylypen          #+#    #+#             */
/*   Updated: 2016/12/02 18:43:30 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lst_del_each(t_list **alst, void (*del)(void *, size_t))
{
	if ((*alst)->next)
		ft_lst_del_each(&((*alst)->next), del);
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
}

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if ((*alst)->next)
		ft_lst_del_each(&(*alst)->next, del);
	del((*alst)->content, (*alst)->content_size);
	ft_memdel((void *)alst);
}
