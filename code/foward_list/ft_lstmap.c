/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 23:54:48 by adantas-          #+#    #+#             */
/*   Updated: 2024/05/01 23:59:12 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

t_flist	*ft_lstmap(t_flist *self, void *(*f)(void *), void (*del)(void *))
{
	t_flist *copy;

	if (!f)
		return (NULL);
	copy = flist_build(self);
	if (!copy)
		return (NULL);
	ft_lstiter(copy, f);
	return (copy);
}
