/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 23:00:59 by adantas-          #+#    #+#             */
/*   Updated: 2024/04/12 21:41:31 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

int	ft_atoi(t_str nptr)
{
	char	*it;
	bool	neg;
	int		nbr;

	if (nptr.empty(&nptr))
		return (0);
	it = nptr.find_first_not_ptr(&nptr, " \t\r\f\n\v");
	neg = *it == '-';
	it = it + 1 * (neg || *it == '+');
	nbr = 0;
	while (ft_isdigit(*it))
		nbr = nbr * 10 + (*it++ - '0');
	if (neg)
		return (-nbr);
	return (nbr);
}
