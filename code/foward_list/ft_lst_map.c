/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 23:54:48 by adantas-          #+#    #+#             */
/*   Updated: 2024/05/02 22:28:49 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

t_flist	*ft_lst_map(t_flist *self, void *(*f)(void *), void (*del)(void *))
{
	t_flist *copy;
	t_list	*it;
	t_list	*tmp;

	if (!f)
		return (NULL);
	*copy = flist_build(NULL);
	if (!copy)
		return (NULL);
	it = self->_head;
	while (it)
	{
		tmp = ft_lst_new(f(it->content));
		if (!tmp)
		{
			flist_unbuild(copy);
			return (NULL);
		}
		copy->add_back(copy, tmp);
		it = it->next;
	}
	return (copy);
}
