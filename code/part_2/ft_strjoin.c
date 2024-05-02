/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:09:32 by adantas-          #+#    #+#             */
/*   Updated: 2024/04/29 19:15:33 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	lhs_len;
	size_t	rhs_len;

	if (!s1 && s2)
		return (ft_strdup(s2));
	else if (!s2 && s1)
		return (ft_strdup(s1));
	else if (!s1 && !s2)
		return (NULL);
	lhs_len = ft_strlen(s1);
	rhs_len = ft_strlen(s2);
	joined = (char *)ft_calloc(lhs_len + rhs_len + 1, sizeof(char));
	if (!joined)
		return (NULL);
	ft_strlcpy(joined, s1, lhs_len + 1);
	ft_strlcat(joined, s2, lhs_len + rhs_len + 1);
	return (joined);
}
