/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_string_fun1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 21:13:16 by adantas-          #+#    #+#             */
/*   Updated: 2024/04/15 23:42:58 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/t_string.h"

bool	string_empty(t_str *self)
{
	return (self->_size == 0);
}

char	*string_ff_ptr(t_str *self, char *find)
{
	char	*it;
	size_t	i;

	if (*find == 0)
		return (NULL);
	it = self->_str;
	while (it != self->end(self))
	{
		i = 0;
		while (find[i] != 0)
			if (find[i++] == *it)
				return (it);
		++it;
	}
	return (NULL);
}

size_t	string_ff_pos(t_str *self, char *find)
{
	size_t	pos;
	size_t	i;

	if (*find == 0)
		return (-1);
	pos = 0;
	while (self->at_ptr(self, pos) != self->end(self))
	{
		i = 0;
		while (find[i] != 0)
			if (find[i++] == self->at(self, pos))
				return (pos);
		++pos;
	}
	return (-1);
}

char	*string_ffn_ptr(t_str *self, char *find)
{
	char	*it;
	size_t	i;

	if (*find == 0)
		return (NULL);
	it = self->_str;
	while (it != self->end(self))
	{
		i = 0;
		while (find[i] != 0)
		{
			if (find[i] == *it)
				break ;
			++i;
		}
		if (find[i] == 0)
			return (it);
		++it;
	}
	return (NULL);
}

size_t	string_ffn_pos(t_str *self, char *find)
{
	size_t	pos;
	size_t	i;

	if (*find == 0)
		return (-1);
	pos = 0;
	while (self->at_ptr(self, pos) != self->end(self))
	{
		i = 0;
		while (find[i] != 0)
		{
			if (find[i] == self->at(self, pos))
				break ;
			++i;
		}
		if (find[i] == 0)
			return (pos);
		++pos;
	}
	return (-1);
}
