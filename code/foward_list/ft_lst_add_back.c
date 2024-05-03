/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 21:35:55 by adantas-          #+#    #+#             */
/*   Updated: 2024/05/02 22:44:49 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void	ft_lst_add_back(t_flist *self, t_list *nw)
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
		self->_tail->next = nw;
		self->_tail = nw;
	}
	++self->_size;
}
