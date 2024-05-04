/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 21:30:21 by adantas-          #+#    #+#             */
/*   Updated: 2024/05/04 09:55:29 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif
# include "libft.h"

typedef struct s_gnl	t_gnl;
typedef char			*(*t_gnl_get_line)(t_gnl *);
typedef void			(*t_gnl_set_fd)(t_gnl *, int);
typedef void			(*t_gnl_clear)(t_gnl *);

struct s_gnl
{
	int		_fd;
	char	*_buffer;

	t_gnl_get_line	get_line;
	t_gnl_set_fd	set_fd;
	t_gnl_clear		clear;
};

t_gnl	gnl_build(t_gnl *self, int fd);
void	gnl_unbuild(t_gnl *self);

void	ft_gnl_clear(t_gnl *self);
char	*ft_gnl_read(t_gnl *self);
void	ft_gnl_set_fd(t_gnl *self, int fd);

#endif
