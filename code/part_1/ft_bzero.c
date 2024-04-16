/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 21:43:01 by adantas-          #+#    #+#             */
/*   Updated: 2024/04/15 23:35:58 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
