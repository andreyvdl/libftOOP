/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:32:47 by adantas-          #+#    #+#             */
/*   Updated: 2024/05/04 14:33:42 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

int	print_char(t_printf *self, bool is_percent)
{
	int	c;

	if (is_percent)
		c = '%';
	else
		c = va_arg(self->ap, int);
	ft_putchar_fd(c, self->fd);
	return (1);
}
