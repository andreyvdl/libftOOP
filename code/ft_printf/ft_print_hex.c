/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:35:42 by adantas-          #+#    #+#             */
/*   Updated: 2024/05/04 19:02:20 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

static int	count_houses(long int ptr)
{
	int	i;

	i = 0;
	while (ptr < -15 || ptr > 15)
	{
		ptr /= 16;
		++i;
	}
	return (i);
}

static void	fill_array(char *str, char *ref, long int ptr, int i)
{
	while (ptr < -15 || ptr > 15)
		fill_array(str, ref, ptr / 16, i - 1);
	if (ptr < 0)
		str[i] = ref[-(ptr % 16)];
	else
		str[i] = ref[ptr % 16];
}

int	print_hex(t_printf *self, char *ref, bool is_ptr)
{
	long int	ptr;
	char		str[23];
	int			ret;
	
	ptr = va_arg(self->ap, long int);
	ft_bzero(str, 23);
	if (is_ptr)
	{
		if (!ptr)
		{
			ft_putstr_fd("(nil)", self->fd);
			return (5);
		}
		ft_strlcpy(str, "0x", 3);
		fill_array(str, ref, ptr, 2 + count_houses(ptr));
	}
	else
		fill_array(str, ref, ptr, count_houses(ptr));
	ft_putstr_fd(str, self->fd);
	ret = ft_strlen(str);
	return (ret);
}
