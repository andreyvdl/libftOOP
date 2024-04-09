/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_string.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:44:02 by adantas-          #+#    #+#             */
/*   Updated: 2024/04/08 23:49:02 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef T_STRING_H
# define T_STRING_H

# include <stdlib.h>
# include <stdbool.h>

typedef struct s_str	t_str;

struct s_str
{
	char	*_str;
	size_t	_size;

	t_str	*(*copy_self)(t_str *self);
	char	*(*begin)(t_str *self);
	char	*(*end)(t_str *self);
	char	*(*at_ptr)(t_str *self, size_t pos);
	char	*(*find_first_ptr)(t_str *self, char *find, size_t start);
	char	*(*find_last_ptr)(t_str *self, char *find, size_t start);
	char	*(*find_not_first_ptr)(t_str *self, char *find, size_t start);
	char	*(*find_not_last_ptr)(t_str *self, char *find, size_t start);
	void	(*build_empty)(t_str *self);
	void	(*build_str)(t_str *self, char *str);
	void	(*destroy)(t_str *self);
	void	(*copy_to)(t_str *self, t_str *that);
	char	(*at_value)(t_str *self, size_t pos);
	void	(*erase)(t_str *self, size_t start, size_t end);
	bool	(*empty)(t_str *self);
	size_t	(*find_first_pos)(t_str *self, char *find, size_t start);
	size_t	(*find_last_pos)(t_str *self, char *find, size_t start);
	size_t	(*find_not_first_pos)(t_str *self, char *find, size_t start);
	size_t	(*find_not_last_pos)(t_str *self, char *find, size_t start);
	size_t	(*get_size)(t_str *self);
	void	(*set_str)(t_str *self, char *str);
};

#endif
