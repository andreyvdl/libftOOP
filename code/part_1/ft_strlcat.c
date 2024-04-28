/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 23:35:00 by adantas-          #+#    #+#             */
/*   Updated: 2024/04/28 15:45:33 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t sz)
{
	size_t	start;

	start = ft_strlen(dst);
	if (sz == 0 || start >= sz)
		return (sz + ft_strlen(src));
	ft_memcpy(dst + start, (void *)src, sz - start);
	dst[sz] = 0;
	return (start + ft_strlen(src));
}
