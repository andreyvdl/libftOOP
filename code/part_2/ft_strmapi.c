/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:16:13 by adantas-          #+#    #+#             */
/*   Updated: 2024/04/29 19:20:56 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_s;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	new_s = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!new_s)
		return (NULL);
	i = 0;
	while (*s)
	{
		new_s[i] = f(i, *s++);
		++i;
	}
	return (new_s);
}
