/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 23:00:59 by adantas-          #+#    #+#             */
/*   Updated: 2024/04/19 00:05:27 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

int	ft_atoi(const char *nptr)
{
	bool		neg;
	int			nbr;

	if (nptr[0] == 0)
		return (0);
	while (ft_isspace(*nptr))
		++nptr;
	neg = *nptr == '-';
	nptr = nptr + 1 * (neg || *nptr == '+');
	nbr = 0;
	while (ft_isdigit(*nptr))
		nbr = nbr * 10 + (*nptr++ - '0');
	if (neg)
		return (-nbr);
	return (nbr);
}
