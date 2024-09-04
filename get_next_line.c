/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:20:19 by girts             #+#    #+#             */
/*   Updated: 2024/07/19 21:54:27 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	handle_remaining(t_gnl *data, char	**remaining, \
								char	**newline_pos)
{
	data->line = *remaining;
	*remaining = NULL;
	*newline_pos = ft_strchr(data->line, '\n');
	if (*newline_pos)
	{
		if (*(*newline_pos + 1))
		{
			*remaining = ft_strdup((*newline_pos + 1));
			if (!(*remaining))
			{
				free(data->buffer);
				free(data->line);
				return (0);
			}
		}
		*(*newline_pos + 1) = '\0';
		free(data->buffer);
		return (1);
	}
	data->line_len = 0;
	while (data->line[data->line_len] != '\0')
		data->line_len++;
	return (-1);
}

static int	handle_newline(t_gnl *data, char	**newline_pos, char	**remaining)
{
	if (*(*newline_pos + 1))
	{
		*remaining = ft_strdup((*newline_pos + 1));
		if (!(*remaining))
		{
			free(data->buffer);
			free(data->line);
			return (0);
		}
	}
	*(*newline_pos + 1) = '\0';
	data->buffer_len = *newline_pos - data->buffer + 1;
	return (1);
}

static int	get_line(t_gnl *data, int fd, char	**newline_pos, char	**remaining)
{
	int			res;

	data->bytes_read = read(fd, data->buffer, BUFFER_SIZE);
	if (data->bytes_read <= 0)
		return (2);
	data->buffer[data->bytes_read] = '\0';
	data->buffer_len = data->bytes_read;
	*newline_pos = ft_strchr(data->buffer, '\n');
	if (*newline_pos)
	{
		res = handle_newline(data, newline_pos, remaining);
		if (res == 0)
			return (0);
	}
	res = handle_buffer(data, newline_pos);
	if (res == 0)
		return (0);
	else if (res == 1)
		return (1);
	return (-1);
}

static int	init_data(t_gnl *data, int fd, char **newline_pos, \
						char **remaining)
{
	int	res;

	res = -1;
	data->line_len = 0;
	data->buffer_len = 0;
	data->line = NULL;
	data->buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!data->buffer)
		return (0);
	while (1)
	{
		if (*remaining)
			res = handle_remaining(data, remaining, newline_pos);
		if (res && res >= 0)
			return (res);
		res = get_line(data, fd, newline_pos, remaining);
		if (res == 2)
			break ;
		else if (res >= 0)
			return (res);
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	static char	*remaining = NULL;
	char		*newline_pos;
	t_gnl		data;
	int			res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	res = init_data(&data, fd, &newline_pos, &remaining);
	if (res == 0)
		return (NULL);
	else if (res == 1)
		return (data.line);
	free(data.buffer);
	if (data.bytes_read < 0 || (data.bytes_read == 0 && \
			(!data.line || !data.line[0])))
	{
		free(data.line);
		return (NULL);
	}
	return (data.line);
}
