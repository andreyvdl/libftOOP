/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_string_fun2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 21:15:14 by adantas-          #+#    #+#             */
/*   Updated: 2024/04/12 22:59:23 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/t_string.h"

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

void	string_set(t_str *self, char *str)
{
	string_destroy(self);
	string_constructor1(self, str);
}

void	string_erase(t_str *self, size_t start, size_t n)
{
	char	*str;
	size_t	i[2];

	if (start + n < start || start + n < n \
	|| self->begin(self) + start + n >= self->end(self))
		n = self->_size - start;
	str = malloc(sizeof(char) * (self->_size - n));
	i[0] = -1;
	while (++(i[0]) != start)
		str[i[0]] = self->_str[i[0]];
	i[1] = i[0];
	while (i[0] <= start + n)
		++(i[0]);
	while (i[0] < self->_size)
	{
		str[i[1]] = self->_str[i[0]];
		++(i[0]);
		++(i[1]);
	}
	str[i[1]] = 0;
	string_destroy(self);
	self->_str = str;
	self->_size = self->_size - n;
}

char	*string_fl_ptr(t_str *self, char *find)
{
	char	*it;
	char	*it2;
	size_t	i;

	if (*find == 0)
		return (NULL);
	it = self->_str;
	it2 = NULL;
	while (it != self->end(self))
	{
		i = 0;
		while (find[i] != 0)
		{
			if (find[i++] == *it)
			{
				it2 = it;
				break ;
			}
		}
		it++;
	}
	return (it2);
}
