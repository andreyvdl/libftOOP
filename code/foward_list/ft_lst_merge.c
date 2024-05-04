/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_merge.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:57:36 by adantas-          #+#    #+#             */
/*   Updated: 2024/05/03 21:06:29 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void	ft_lst_merge(t_flist *self, t_flist *other, bool copy)
{
	t_list	*tmp;

	if (copy)
	{
		tmp = other->_head;
		while (tmp)
		{
			self->add_back(self, ft_lst_new(tmp->content));
			tmp = tmp->next;
		}
	}
	else
	{
		self->_tail->next = other->_head;
		self->_tail = other->_tail;
		self->_size += other->_size;
	}
}
