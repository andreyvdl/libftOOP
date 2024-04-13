/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_string_fun3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 21:17:05 by adantas-          #+#    #+#             */
/*   Updated: 2024/04/12 21:17:16 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/t_string.h"

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
