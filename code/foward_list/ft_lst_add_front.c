/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 21:41:48 by adantas-          #+#    #+#             */
/*   Updated: 2024/05/02 22:14:43 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void	ft_lst_add_front(t_flist *self, t_list *nw)
{
	if (!nw)
		return ;
	if (!self->_head)
	{
		self->_head = nw;
		self->_tail = nw;
	}
	else
	{
		nw->next = self->_head;
		self->_head = nw;
	}
}
