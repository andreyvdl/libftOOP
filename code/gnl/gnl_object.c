/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 22:10:03 by adantas-          #+#    #+#             */
/*   Updated: 2024/05/04 09:56:47 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

t_gnl	gnl_build(t_gnl *self, int fd)
{
	t_gnl	tmp;

	tmp._fd = fd;
	tmp._buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	tmp.get_line = &ft_gnl_read;
	tmp.set_fd = &ft_gnl_set_fd;
	tmp.clear = &ft_gnl_clear;
	if (self)
		*self = tmp;
	return (tmp);
}

void	gnl_unbuild(t_gnl *self)
{
	close(self->_fd);
	self->clear(self);
}
