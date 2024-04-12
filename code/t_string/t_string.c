/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_string.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:43:26 by adantas-          #+#    #+#             */
/*   Updated: 2024/04/11 23:59:23 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/t_string.h"

void	string_constructor0(t_str *self)
{
	self->_size = 0;
	self->_str = malloc(sizeof(char) * 1);
	if (self->_str == NULL)
		return ;
	str_set_functions(self);
}

void	string_constructor1(t_str *self, char *str)
{
	size_t	size;

	size = 0;
	while (str[size] != '\0')
		++size;
	self->_str = malloc(sizeof(char) * (size + 1));
	if (self->_str == NULL)
		return ;
	self->_size = size;
	size = -1;
	while (++size <= self->_size)
		self->_str[size] = str[size];
	str_set_functions(self);
}

void	string_destroy(t_str *self)
{
	free(self->_str);
	self->_size = 0;
}

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

bool	string_empty(t_str *self)
{
	return (self->_size == 0);
}

void	string_copy_to(t_str *self, t_str *that)
{
	string_destroy(that);
	string_constructor1(that, self->_str);
}

void	string_copy_from(t_str *self, t_str *that)
{
	string_destroy(self);
	string_constructor1(self, that->_str);
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

void	string_set(t_str *self, char *str)
{
	string_destroy(self);
	string_constructor1(self, str);
}

void	string_erase(t_str *self, size_t start, size_t n) // REDO
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
			if (find[i++] == *it)
			{
				it2 = it;
				break ;
			}
		it++;
	}
	return (it2);
}

char	*string_fln_ptr(t_str *self, char *find)
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
			if (find[i] == *it)
				break;
			++i;
		}
		if (find[i] == 0)
			it2 = it;
		++it;
	}
	return (it2);
}

size_t	string_fl_pos(t_str *self, char *find)
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
			if (find[i++] == self->at(self, *pos))
			{
				pos[1] = pos[0];
				break ;
			}
		}
		++(*pos);
	}
	return (pos[1]);
}

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
