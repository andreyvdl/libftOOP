/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:52:08 by adantas-          #+#    #+#             */
/*   Updated: 2024/04/28 17:52:50 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void	*ft_memmove(void *dest, void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dest || !src)
		return (dest);
	if (dest > src)
	{
		d = dest + n - 1;
		s = src + n - 1;
		while (n--)
			*d-- = *s--;
		return (dest);
	}
	d = dest;
	s = src;
	while (n--)
		*d++ = *s++;
	return (dest);
}
