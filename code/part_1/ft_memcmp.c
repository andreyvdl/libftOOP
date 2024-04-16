/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:52:41 by adantas-          #+#    #+#             */
/*   Updated: 2024/04/15 22:45:31 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*lhs = s1;
	const unsigned char	*rhs = s2;

	if (n == 0)
		return (0);
	while (*lhs == *rhs && --n)
	{
		++lhs;
		++rhs;
	}
	return (*lhs - *rhs);
}
