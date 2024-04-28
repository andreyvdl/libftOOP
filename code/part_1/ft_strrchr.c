/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:04:39 by adantas-          #+#    #+#             */
/*   Updated: 2024/04/28 19:54:09 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*rit;

	rit = (char *)s + ft_strlen(s);
	while (rit != s)
	{
		if (*rit == c)
			return (rit);
		--rit;
	}
	if (*rit == c)
		return (rit);
	return (NULL);
}
