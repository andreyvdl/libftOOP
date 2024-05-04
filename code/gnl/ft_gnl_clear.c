/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 23:09:41 by adantas-          #+#    #+#             */
/*   Updated: 2024/05/03 23:11:47 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void	ft_gnl_clear(t_gnl *self)
{
	if (self->_buffer)
		free(self->_buffer);
	self->_buffer = NULL;
}
