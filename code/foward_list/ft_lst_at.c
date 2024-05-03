/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 22:30:31 by adantas-          #+#    #+#             */
/*   Updated: 2024/05/02 22:31:47 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

t_list	*ft_lst_at(t_flist *self, size_t n)
{
	t_list	*tmp;

	if (n >= self->_size)
		return (NULL);
	tmp = self->_head;
	while (n--)
		tmp = tmp->next;
	return (tmp);
}
