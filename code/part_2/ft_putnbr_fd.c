/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 23:46:17 by adantas-          #+#    #+#             */
/*   Updated: 2024/04/28 23:50:06 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

static void	recursive_transformation(char *nbr, int n, size_t i)
{
	if (n / 10)
		recursive_transformation(nbr, n / 10, i + 1);
	if (n < 0)
		nbr[i] = '0' - n % 10;
	else
		nbr[i] = '0' + n % 10;
}

void	ft_putnbr_fd(int n, int fd)
{
	char	nbr[12];

	if (fd < 0)
		return ;
	if (n < 0)
	{
		nbr[0] = '-';
		recursive_transformation(nbr, n, 1);
	}
	else
		recursive_transformation(nbr, n, 0);
	write(fd, nbr, ft_strlen(nbr));
}
