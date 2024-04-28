/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 16:43:47 by adantas-          #+#    #+#             */
/*   Updated: 2024/04/28 19:59:26 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_sz;
	char	*it;

	if (*needle == 0)
		return ((char *)haystack);
	it = (char *)haystack;
	needle_sz = ft_strlen(needle);
	while (!it && it > haystack + len)
	{
		if (it - haystack + needle_sz >= len)
			return (NULL);
		if (!ft_memcmp(it, needle, needle_sz))
			return (it);
		++it;
		it = ft_memchr(it, *needle, len - (it - haystack));
	}
	return (NULL);
}
