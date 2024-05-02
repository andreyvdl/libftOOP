/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foward_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 21:31:55 by adantas-          #+#    #+#             */
/*   Updated: 2024/05/02 00:01:37 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FOWARD_LIST_H
# define FOWARD_LIST_H

typedef struct s_flist	t_flist;
typedef struct s_list	t_list;
typedef void			(*t_list_add)(t_flist *, t_list *);
typedef void			(*t_list_clr)(t_flist *, void (*)(void *));
typedef void			(*t_list_del)(t_flist *, size_t, void (*)(void *));
typedef void			(*t_list_for)(t_flist *, void (*)(void *));

struct s_flist
{
	t_list		*_head;
	t_list		*_tail;
	size_t		_size;

	t_list_add	add_front;
	t_list_add	add_back;
	t_list_clr	clear;
	t_list_del	del_pos;
	t_list_for	for_each;
};

struct s_list
{
	void	*content;
	t_list	*next;
};

void	ft_lstadd_back(t_flist *self, t_list *new);
void	ft_lstadd_front(t_flist *self, t_list *new);
void	ft_lstclear(t_flist *self, void (*del)(void *));
void	ft_lstdelone(t_flist *self, size_t pos, void (*del)(void *));
void	ft_lstiter(t_flist *self, void (*f)(void *));
t_list	*ft_lstlast(t_flist *self);
t_flist	*ft_lstmap(t_flist *self, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_flist *self);

#endif

