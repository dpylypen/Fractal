/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 16:34:16 by dpylypen          #+#    #+#             */
/*   Updated: 2016/12/01 16:41:45 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int ch)
{
	if ((unsigned char)ch == '\t' || (unsigned char)ch == '\n'
		|| (unsigned char)ch == '\v' || (unsigned char)ch == '\f'
		|| (unsigned char)ch == '\r' || (unsigned char)ch == ' ')
		return (1);
	return (0);
}
