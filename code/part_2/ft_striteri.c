/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 23:52:36 by adantas-          #+#    #+#             */
/*   Updated: 2024/04/29 00:01:03 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	char	*it;

	if (!s || !f)
		return ;
	it = s;
	while (*it)
	{
		f(it - s, it);
		++it;
	}
}
