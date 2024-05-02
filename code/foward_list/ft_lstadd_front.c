/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 21:41:48 by adantas-          #+#    #+#             */
/*   Updated: 2024/05/02 00:03:27 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void	ft_lstadd_front(t_flist *self, t_list *new)
{
	if (!new)
		return ;
	if (!self->_head)
	{
		self->_head = new;
		self->_tail = new;
	}
	else
	{
		new->next = self->_head;
		self->_head = new;
	}
}
