/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 23:46:17 by adantas-          #+#    #+#             */
/*   Updated: 2024/05/04 17:57:32 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

static void	recursive_print(int n, int fd)
{
	char	c;

	if (n / 10)
		recursive_print(n / 10, fd);
	if (n < 0)
		c = '0' - n % 10;
	else
		c = '0' + n % 10;
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n < 0)
	{
		write(fd, "-", 1);
		recursive_print(n, fd);
	}
	else
		recursive_print(n, fd);
}
