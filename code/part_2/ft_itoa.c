/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 21:24:22 by adantas-          #+#    #+#             */
/*   Updated: 2024/05/04 18:40:46 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

static int	count_houses(ssize_t n)
{
	int	i;

	i = 0;
	while (n < -9 || n > 9)
	{
		n /= 10;
		++i;
	}
	return (i);
}

static void	recursive_transformation(char *nbr, ssize_t n, size_t i)
{
	if (n < -9 || n > 9)
		recursive_transformation(nbr, n / 10, i - 1);
	if (n < 0)
		nbr[i] = '0' - n % 10;
	else
		nbr[i] = '0' + n % 10;
}

char	*ft_itoa(ssize_t n)
{
	char	*nbr;

	nbr = (char *)ft_calloc(21, sizeof(char));
	if (!nbr)
		return (NULL);
	if (n < 0)
	{
		nbr[0] = '-';
		recursive_transformation(nbr, n, count_houses(n) + 1);
		return (nbr);
	}
	recursive_transformation(nbr, n, count_houses(n));
	return (nbr);
}
