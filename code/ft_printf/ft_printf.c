/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 12:29:14 by adantas-          #+#    #+#             */
/*   Updated: 2024/05/04 14:34:35 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

static int	expand_option(t_printf *self, char **it)
{
	static char	*hex[] = {"0123456789abcdef", "0123456789ABCDEF"};
	int			ret;

	++(*it);
	if (!ft_strchr(PRINT_OPTIONS, **it))
		return (print_char(self, true));
	else if (**it == 'p' || **it == 'x' || **it == 'X')
		ret = print_hex(self, hex[**it == 'X'], **it == 'p');
	else if (**it == 'd' || **it == 'i' || **it == 'u')
		ret = print_nbr(self, **it == 'u');
	else if (**it == 'c' || **it == '%')
		ret = print_char(self, **it == '%');
	else if (**it == 's')
		ret = print_str(self);
	++(*it);
	return (ret);
}

int	ft_printf(t_printf *self, const char *format, ...)
{
	int		ret;
	char	*it;

	if (!format)
		return (-1);
	if (!ft_strchr(format, '%'))
		return (write(self->fd, format, ft_strlen(format)));
	ret = 0;
	va_start(self->ap, format);
	it = (char *)format;
	while (*it)
	{
		if (*it == '%')
		{
			write(self->fd, format, it - format);
			ret += expand_option(self, &it);
			format = it;
		}
		else
			++it;
	}
	va_end(self->ap);
	if (format != it)
		ret += write(self->fd, format, it - format);
	return (ret);
}
