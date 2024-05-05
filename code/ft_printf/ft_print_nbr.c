/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:26:12 by adantas-          #+#    #+#             */
/*   Updated: 2024/05/04 15:36:31 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

int	print_nbr(t_printf *self, bool big_endian)
{
	char	*str;
	int		ret;

	if (big_endian)
		str = ft_itoa(va_arg(self->ap, unsigned int));
	else
		str = ft_itoa(va_arg(self->ap, int));
	if (!str)
		return (0);
	ft_putstr_fd(str, self->fd);
	ret = ft_strlen(str);
	free(str);
	return (ret);
}
