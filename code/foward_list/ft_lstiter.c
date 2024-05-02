/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 23:47:14 by adantas-          #+#    #+#             */
/*   Updated: 2024/05/02 00:02:08 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void	ft_lstiter(t_flist *self, void (*f)(void *))
{
	t_list	*tmp;

	if (!f)
		return ;
	tmp = self->_head;
	while (tmp)
	{
		f(tmp->content);
		tmp = tmp->next;
	}
}
