/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 23:10:07 by adantas-          #+#    #+#             */
/*   Updated: 2024/05/04 11:29:44 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

static char	*get_that_line(t_gnl *self, char *line, char *pos)
{
	char	*tmp;

	tmp = ft_substr(self->_buffer, 0, pos - self->_buffer + 1);
	if (!tmp)
		return (NULL);
	ft_memmove(self->_buffer, pos + 1, ft_strlen(pos));
	if (line)
	{
		pos = ft_strjoin(line, tmp);
		free(line);
		free(tmp);
		return (pos);
	}
	else
		return (tmp);
}

static char	*unite_them(t_gnl *self, char *line)
{
	char	*tmp;

	if (line)
	{
		tmp = ft_strjoin(line, self->_buffer);
		free(line);
	}
	else
		tmp = ft_strdup(self->_buffer);
	return (tmp);
}

static char	*read_it(t_gnl *self, char *line)
{
	ssize_t	readed;
	char	*tmp;

	readed = 0;
	while (true)
	{
		readed = read(self->_fd, self->_buffer, BUFFER_SIZE);
		if (readed == -1)
		{
			if (line)
				free(line);
			return (NULL);
		}
		if (readed == 0)
			break ;
		self->_buffer[readed] = '\0';
		tmp = ft_strchr(self->_buffer, '\n');
		if (tmp)
			return (get_that_line(self, line, tmp));
		else
			line = unite_them(self, line);
	}
	return (line);
}

char	*ft_gnl_read(t_gnl *self)
{
	char	*tmp;
	char	*line;

	if (read(self->_fd, NULL, 0) == -1)
		return (NULL);
	tmp = ft_strchr(self->_buffer, '\n');
	line = NULL;
	if (tmp)
	{
		line = ft_substr(self->_buffer, 0, tmp - self->_buffer + 1);
		ft_memmove(self->_buffer, tmp + 1, ft_strlen(tmp));
		return (line);
	}
	if (self->_buffer[0] != '\0')
	{
		line = ft_strdup(self->_buffer);
		return (read_it(self, line));
	}
	return (read_it(self, NULL));
}
