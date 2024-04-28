/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:52:41 by adantas-          #+#    #+#             */
/*   Updated: 2024/04/28 17:51:57 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*lhs;
	unsigned char	*rhs;

	if (n == 0 || s1 == s2)
		return (0);
	if (!s1 || !s2)
		return (s1 - s2);
	lhs = (unsigned char *)s1;
	rhs = (unsigned char *)s2;
	while (*lhs == *rhs && --n)
	{
		++lhs;
		++rhs;
	}
	return (*lhs - *rhs);
}
