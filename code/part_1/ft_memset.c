/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 23:04:03 by adantas-          #+#    #+#             */
/*   Updated: 2024/04/28 17:53:02 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*it;

	if (!s)
		return (NULL);
	it = s;
	while (n--)
		*it++ = c;
	return (s);
}
