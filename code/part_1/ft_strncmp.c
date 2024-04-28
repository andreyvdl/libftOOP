/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:53:38 by adantas-          #+#    #+#             */
/*   Updated: 2024/04/28 19:52:48 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*lhs;
	unsigned char	*rhs;

	if (n == 0 || s1 == s2)
		return (0);
	lhs = (unsigned char *)s1;
	rhs = (unsigned char *)s2;
	while (*lhs == *rhs && *lhs != 0 && *rhs != 0 && --n)
	{
		++lhs;
		++rhs;
	}
	return (lhs - rhs);
}
