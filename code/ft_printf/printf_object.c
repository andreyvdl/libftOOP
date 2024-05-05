/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:50:23 by adantas-          #+#    #+#             */
/*   Updated: 2024/05/04 11:51:47 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

t_printf	printf_build(t_printf *self, int fd)
{
	t_printf	tmp;

	tmp.fd = fd;
	tmp.print = &ft_printf;
	if (self)
		*self = tmp;
	return (tmp);
}

void	printf_unbuild(t_printf *self)
{
	close(self->fd);
}
