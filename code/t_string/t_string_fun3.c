/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_string_fun3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 21:17:05 by adantas-          #+#    #+#             */
/*   Updated: 2024/04/16 00:01:17 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

size_t	string_fln_pos(t_str *self, char *find)
{
	size_t	pos[2];
	size_t	i;

	if (*find == 0)
		return (-1);
	pos[0] = 0;
	pos[1] = -1;
	while (self->at_ptr(self, *pos) != self->end(self))
	{
		i = 0;
		while (find[i] != 0)
		{
			if (find[i] == self->at(self, *pos))
				break ;
			++i;
		}
		if (find[i] == 0)
			pos[1] = pos[0];
		++(*pos);
	}
	return (pos[1]);
}

void	string_append(t_str *self, char *content)
{
	char	*new_str;
	size_t	size;
	size_t	tmp;

	size = 0;
	while (content[size] != 0)
		++size;
	new_str = malloc(sizeof(char) * (1 + (size + self->_size)));
	ft_memmove(new_str, self->_str, self->_size);
	ft_memmove(new_str + self->_size + 1, content, size);
	tmp = size + self->_size;
	string_destroy(self);
	self->_str = new_str;
	self->_size = tmp;
}
