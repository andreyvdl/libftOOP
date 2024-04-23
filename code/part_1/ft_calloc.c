/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 23:00:16 by adantas-          #+#    #+#             */
/*   Updated: 2024/04/22 23:26:51 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	sum;

	if (nmemb == 0 || size == 0)
		return (NULL);
	sum = nmemb * size;
	if (sum > INT32_MAX || sum > PTRDIFF_MAX || sum / nmemb != size)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ptr = malloc(sum);
	if (ptr == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_bzero(ptr, sum);
	return (ptr);
}
