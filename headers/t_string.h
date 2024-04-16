/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_string.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:44:02 by adantas-          #+#    #+#             */
/*   Updated: 2024/04/15 23:42:14 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef T_STRING_H
# define T_STRING_H

# include <stdlib.h>
# include <stdbool.h>

typedef struct s_str	t_str;
typedef char			*(*t_str_self2ptr)(t_str *);
typedef char			*(*t_str_find_ptr)(t_str *, char *);
typedef char			*(*t_str_at_ptr)(t_str *, size_t);
typedef void			(*t_str_set)(t_str *, char *);
typedef void			(*t_str_erase)(t_str *, size_t, size_t);
typedef size_t			(*t_str_size)(t_str *);
typedef size_t			(*t_str_find_pos)(t_str *, char *);
typedef char			(*t_str_at)(t_str *, size_t);
typedef bool			(*t_str_empty)(t_str *);
typedef void			(*t_str_append)(t_str *, char *);

struct s_str
{
	char			*_str;
	size_t			_size;

	t_str_self2ptr	begin;
	t_str_self2ptr	end;
	t_str_at_ptr	at_ptr;
	t_str_find_ptr	find_first_ptr;
	t_str_find_ptr	find_last_ptr;
	t_str_find_ptr	find_first_not_ptr;
	t_str_find_ptr	find_last_not_ptr;
	t_str_at		at;
	t_str_erase		erase;
	t_str_empty		empty;
	t_str_find_pos	find_first_pos;
	t_str_find_pos	find_last_pos;
	t_str_find_pos	find_first_not_pos;
	t_str_find_pos	find_last_not_pos;
	t_str_size		get_size;
	t_str_set		set;
	t_str_append	append;	
};

void	string_constructor0(t_str *self);
void	string_constructor1(t_str *self, char *str);
void	string_destroy(t_str *self);

size_t	string_get_size(t_str *self);
char	*string_begin(t_str *self);
char	*string_end(t_str *self);
char	*string_at_ptr(t_str *self, size_t pos);
char	string_at_value(t_str *self, size_t pos);
bool	string_empty(t_str *self);
void	string_copy_to(t_str *self, t_str *that);
void	string_copy_from(t_str *self, t_str *that);
char	*string_ff_ptr(t_str *self, char *find);
size_t	string_ff_pos(t_str *self, char *find);
char	*string_ffn_ptr(t_str *self, char *find);
size_t	string_ffn_pos(t_str *self, char *find);
void	string_set(t_str *self, char *str);
void	string_erase(t_str *self, size_t start, size_t n);
char	*string_fl_ptr(t_str *self, char *find);
char	*string_fln_ptr(t_str *self, char *find);
size_t	string_fl_pos(t_str *self, char *find);
size_t	string_fln_pos(t_str *self, char *find);
void	string_append(t_str *self, char *content);

#endif
