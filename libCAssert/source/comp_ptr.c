/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:13:51 by adantas-          #+#    #+#             */
/*   Updated: 2024/04/24 22:06:09 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libassert.h"

int	le_ptr(void *result, void *expect)
{
	return (result <= expect);
}

int	lt_ptr(void *result, void *expect)
{
	return (result < expect);
}

int	eq_ptr(void *result, void *expect)
{
	return (result == expect);
}

int	gt_ptr(void *result, void *expect)
{
	return (result > expect);
}

int	ge_ptr(void *result, void *expect)
{
	return (result >= expect);
}
