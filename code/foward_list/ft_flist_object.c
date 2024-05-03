/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flist_object.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:59:08 by adantas-          #+#    #+#             */
/*   Updated: 2024/05/03 13:56:25 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/foward_list.h"

t_flist	flist_build(t_flist *self)
{
	t_flist	tmp;

	tmp._head = NULL;
	tmp._tail = NULL;
	tmp._size = 0;
	tmp.add_front = &ft_lst_add_front;
	tmp.add_back = &ft_lst_add_back;
	tmp.clear = &ft_lst_clear;
	tmp.del_pos = &ft_lst_del_one;
	tmp.for_each = &ft_lst_iter;
	tmp.at = &ft_lst_at;
	tmp.size = &ft_lst_size;
	tmp.rev = &ft_lst_rev;
	if (self)
		*self = tmp;
	return (tmp);
}

void	flist_unbuild(t_flist *self, void (*del)(void *))
{
	if (del)
		self->clear(self, del);
	else
		self->clear(self, &free);
	self->_head = NULL;
	self->_tail = NULL;
	self->_size = 0;
}
