/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_string.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:43:26 by adantas-          #+#    #+#             */
/*   Updated: 2024/04/12 22:58:03 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/t_string.h"

static void	string_set_functions(t_str *self)
{
	self->begin = &string_begin;
	self->end = &string_end;
	self->at_ptr = &string_at_ptr;
	self->find_first_ptr = &string_ff_ptr;
	self->find_last_ptr = &string_fl_ptr;
	self->find_first_not_ptr = &string_ffn_ptr;
	self->find_last_not_ptr = &string_fln_ptr;
	self->copy_to = &string_copy_to;
	self->copy_from = &string_copy_from;
	self->at = &string_at_value;
	self->erase = &string_erase;
	self->empty = &string_empty;
	self->find_first_pos = &string_ff_pos;
	self->find_last_pos = &string_fl_pos;
	self->find_first_not_pos = &string_ffn_pos;
	self->find_last_not_pos = &string_fln_pos;
	self->get_size = &string_get_size;
	self->set = &string_set;
}

void	string_constructor0(t_str *self)
{
	self->_size = 0;
	self->_str = malloc(sizeof(char) * 1);
	if (self->_str == NULL)
		return ;
	string_set_functions(self);
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
	string_set_functions(self);
}

void	string_destroy(t_str *self)
{
	free(self->_str);
	self->_size = 0;
}
