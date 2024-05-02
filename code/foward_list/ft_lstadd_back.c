/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 21:35:55 by adantas-          #+#    #+#             */
/*   Updated: 2024/05/02 00:03:54 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void	ft_lstadd_back(t_flist *self, t_list *new)
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
		self->_tail->next = new;
		self->_tail = new;
	}
}
