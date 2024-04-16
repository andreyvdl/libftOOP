/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_string_fun0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 21:11:25 by adantas-          #+#    #+#             */
/*   Updated: 2024/04/15 23:42:19 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/t_string.h"

size_t	string_get_size(t_str *self)
{
	return (self->_size);
}

char	*string_begin(t_str *self)
{
	return (self->_str);
}

char	*string_end(t_str *self)
{
	return (self->_str + self->_size);
}

char	*string_at_ptr(t_str *self, size_t pos)
{
	return (self->_str + pos);
}

char	string_at_value(t_str *self, size_t pos)
{
	return (self->_str[pos]);
}
