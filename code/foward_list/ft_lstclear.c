/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 21:42:20 by adantas-          #+#    #+#             */
/*   Updated: 2024/05/02 00:03:10 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void	ft_lstclear(t_flist *self, void (*del)(void *))
{
	t_list	*tmp[2];

	if (!del)
		return ;
	tmp[0] = self->_head;
	while (tmp[0])
	{
		tmp[1] = tmp[0]->next;
		del(tmp[0]->content);
		free(tmp[0]);
		tmp[0] = tmp[1];
	}
	self->_tail = NULL;
	self->_head = NULL;
}
