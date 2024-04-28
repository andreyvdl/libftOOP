/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 01:09:55 by adantas-          #+#    #+#             */
/*   Updated: 2024/04/28 15:53:08 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t sz)
{
	size_t	ret;

	ret = ft_strlen(src);
	if (sz == 0 || sz <= ret)
		return (ret);
	ft_memcpy(dst, (void *)src, ret);
	dst[ret] = 0;
	return (ret);
}
