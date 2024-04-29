/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 21:24:22 by adantas-          #+#    #+#             */
/*   Updated: 2024/04/28 23:39:28 by adantas-         ###   ########.fr       */
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

char	*ft_itoa(int n)
{
	char	*nbr;

	nbr = (char *)ft_calloc(12, sizeof(char));
	if (!nbr)
		return (NULL);
	if (n < 0)
	{
		nbr[0] = '-';
		recursive_transformation(nbr, n, 1);
		return (nbr);
	}
	recursive_transformation(nbr, n, 0);
	return (nbr);
}
