/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foward_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 21:31:55 by adantas-          #+#    #+#             */
/*   Updated: 2024/05/03 16:33:40 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FOWARD_LIST_H
# define FOWARD_LIST_H
# include "libft.h"

typedef struct s_flist	t_flist;
typedef struct s_list	t_list;
typedef void			(*t_list_add)(t_flist *, t_list *);
typedef void			(*t_list_clr)(t_flist *, void (*)(void *));
typedef void			(*t_list_del)(t_flist *, size_t, void (*)(void *));
typedef t_list			*(*t_list_at)(t_flist *, size_t);
typedef size_t			(*t_list_size)(t_flist *);
typedef void			(*t_list_rev)(t_flist *);

struct s_flist
{
	t_list		*_head;
	t_list		*_tail;
	size_t		_size;

	t_list_add	add_front;
	t_list_add	add_back;
	t_list_at	at;
	t_list_clr	clear;
	t_list_del	del_pos;
	t_list_size	size;
	t_list_rev	rev;
};

struct s_list
{
	void	*content;
	t_list	*next;
};

t_flist	flist_build(t_flist *self);
void	flist_unbuild(t_flist *self, void (*del)(void *));

void	ft_lst_add_back(t_flist *self, t_list *nw);
void	ft_lst_add_front(t_flist *self, t_list *nw);
t_list	*ft_lst_at(t_flist *self, size_t n);
void	ft_lst_clear(t_flist *self, void (*del)(void *));
void	ft_lst_del_one(t_flist *self, size_t pos, void (*del)(void *));
void	ft_lst_iter(t_flist *self, void (*f)(void *));
t_list	*ft_lst_last(t_flist *self);
t_flist	ft_lst_map(t_flist *self, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lst_new(void *content);
void	ft_lst_rev(t_flist *self);
size_t	ft_lst_size(t_flist *self);

#endif
