/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_string_fun2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 21:15:14 by adantas-          #+#    #+#             */
/*   Updated: 2024/04/15 23:53:19 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void	string_set(t_str *self, char *str)
{
	string_destroy(self);
	string_constructor1(self, str);
}

void	string_erase(t_str *self, size_t start, size_t n)
{
	char	*str;
	size_t	tmp;

	if (start + n < start || start + n < n \
	|| self->begin(self) + start + n >= self->end(self))
		n = self->_size - start;
	str = malloc(sizeof(char) * (self->_size - n));
	ft_memmove(str, self->_str, start);
	ft_memmove(str + start, self->_str + start + n, \
		self->end(self) - (self->_str + start + n));
	tmp = self->_size - n;
	string_destroy(self);
	self->_str = str;
	self->_size = tmp;
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
				break ;
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
