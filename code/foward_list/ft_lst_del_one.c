/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_del_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 21:48:41 by adantas-          #+#    #+#             */
/*   Updated: 2024/05/03 13:47:41 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

/*
 * 0 = current node
 * 1 = next node
*/
void	ft_lst_del_one(t_flist *self, size_t pos, void (*del)(void *))
{
	t_list	*tmp[2];

	if (!del)
		return ;
	tmp[0] = self->_head;
	if (pos == 0)
	{
		self->_head = self->_head->next;
		del(tmp[0]->content);
		free(tmp[0]);
		return ;
	}
	while (pos-- > 1)
		tmp[0] = tmp[0]->next;
	tmp[1] = tmp[0]->next;
	tmp[0]->next = tmp[1]->next;
	del(tmp[1]->content);
	free(tmp[1]);
	--self->_size;
}
