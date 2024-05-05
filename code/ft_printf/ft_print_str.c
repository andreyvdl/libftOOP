/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:24:08 by adantas-          #+#    #+#             */
/*   Updated: 2024/05/04 15:27:00 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

int	print_str(t_printf *self)
{
	char	*str;

	str = va_arg(self->ap, char *);
	if (!str)
	{
		ft_putstr_fd("(null)", self->fd);
		return (6);
	}
	ft_putstr_fd(str, self->fd);
	return (ft_strlen(str));
}
