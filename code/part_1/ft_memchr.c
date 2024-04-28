/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:48:37 by adantas-          #+#    #+#             */
/*   Updated: 2024/04/28 18:09:40 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*it;

	if (!s)
		return (NULL);
	it = (unsigned char *)s;
	while (n--)
	{
		if (*it == c)
			return ((void *)it);
		++it;
	}
	return (NULL);
}
