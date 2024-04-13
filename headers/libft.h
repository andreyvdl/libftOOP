/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 19:22:22 by adantas-          #+#    #+#             */
/*   Updated: 2024/04/12 22:32:43 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef LIBFT_H
# define LIBFT_H
# include "t_string.h"

int		ft_atoi(t_str nptr);
int		ft_isdigit(int c);
int		ft_isspace(int c);
void	ft_bzero(void *s, size_t n);

#endif
