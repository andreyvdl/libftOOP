/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 23:26:05 by adantas-          #+#    #+#             */
/*   Updated: 2024/04/19 00:09:28 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_str;
	size_t	len;

	len = ft_strlen(s);
	new_str = ft_calloc(len + 1, 1);
	if (new_str == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_memcpy(new_str, (void *)s, len);
	return (new_str);
}
