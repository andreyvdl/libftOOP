/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 23:52:25 by adantas-          #+#    #+#             */
/*   Updated: 2024/05/01 20:51:13 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

static char	**self_copy(char const *s)
{
	char	**splited;

	splited = (char **)ft_calloc(2, sizeof(char *));
	if (!splited)
		return (NULL);
	splited[0] = ft_strdup(s);
	if (!splited[0])
	{
		free(splited);
		return (NULL);
	}
	return (splited);
}

static size_t	count_words(char const *s, char c)
{
	size_t words;

	words = 0;
	while (*s)
	{
		if (*s != c)
		{
			++words;
			while (*s && *s != c)
				++s;
		}
		while (*s && *s == c)
			++s;
	}
	return (words);
}

static void	free_words(char **split, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(split[i]);
		++i;
	}
}

static bool	get_words(char **split, char const *s, char c)
{
	size_t	sz;
	size_t	i;

	i = 0;
	while (*s)
	{
		sz = 0;
		while (*s && *s == c)
			++s;
		while (s[sz] && s[sz] != c)
			++sz;
		if (sz)
		{
			split[i] = ft_substr(s, 0, sz);
			if (!split[i])
			{
				free_words(split, i);
				return (true);
			}
			++i;
		}
		s += sz;
	}
	return (false);
}

char	**ft_split(char const *s, char c)
{
	char	**splited;

	if (!s)
		return (NULL);
	if (c == 0)
		return (self_copy(s));
	splited = (char **)ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!splited)
		return (NULL);
	if (get_words(splited, s, c))
	{
		free(splited);
		return (NULL);
	}
	return (splited);
}
