/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:36:00 by adantas-          #+#    #+#             */
/*   Updated: 2024/05/04 18:59:31 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define PRINT_OPTIONS "cspdiuxX%"
# include "libft.h"

typedef struct s_printf	t_printf;
typedef int				(*t_print)(t_printf *, const char *, ...);

struct	s_printf
{
	va_list	ap;
	int		fd;

	t_print	print;
};

t_printf	printf_build(t_printf *self, int fd);
void		printf_unbuild(t_printf *self);

int			print_char(t_printf *self, bool is_percent);
int			print_hex(t_printf *self, char *ref, bool is_ptr);
int			print_nbr(t_printf *self, bool big_endian);
int			print_str(t_printf *self);
int			ft_printf(t_printf *self, const char *format, ...);

#endif
