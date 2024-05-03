/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_rev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:33:06 by adantas-          #+#    #+#             */
/*   Updated: 2024/05/03 13:55:13 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

/*
 * 0 = current node
 * 1 = next node
 * 2 = previous node
*/
void	ft_lst_rev(t_flist *self)
{
	t_list	*tmp[3];

	if (self->_size < 2)
		return ;
	tmp[0] = self->_head;
	tmp[2] = NULL;
	self->_head = self->_tail;
	self->_tail = tmp[0];
	while (tmp[0])
	{
		tmp[1] = tmp[0]->next;
		tmp[0]->next = tmp[2];
		tmp[2] = tmp[0];
		tmp[0] = tmp[1];
	}
}
