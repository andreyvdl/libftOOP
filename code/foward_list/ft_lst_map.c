/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 23:54:48 by adantas-          #+#    #+#             */
/*   Updated: 2024/05/03 13:59:19 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

/*
 * 0 = original pointer
 * 1 = modified pointer
*/
t_flist	ft_lst_map(t_flist *self, void *(*f)(void *), void (*del)(void *))
{
	t_flist	copy;
	t_list	*tmp[2];

	copy = flist_build(NULL);
	if (!f)
		return (copy);
	tmp[0] = self->_head;
	while (tmp[0])
	{
		tmp[1] = ft_lst_new(f(tmp[0]->content));
		if (!tmp[1])
		{
			flist_unbuild(&copy, del);
			return (copy);
		}
		copy.add_back(&copy, tmp[1]);
		tmp[0] = tmp[0]->next;
	}
	return (copy);
}
