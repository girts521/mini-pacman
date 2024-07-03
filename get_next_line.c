/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 20:09:35 by girts             #+#    #+#             */
/*   Updated: 2024/06/28 20:45:39 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"
#include "libft.h"
#include <string.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	static char	*remaining = NULL;
	char		*buffer;
	char		*line;
	int			bytes_read;
	size_t		i;
	char		*temp;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (1)
	{
		if (remaining)
		{
			line = ft_strjoin(line, remaining);
			free(remaining);
			remaining = NULL;
		}
		i = 0;
		while (line && line[i])
		{
			if (line[i] == '\n')
			{
				temp = remaining;
				remaining = ft_strjoin(NULL, line + i + 1);
				free(temp);
				line[i + 1] = '\0';
				free(buffer);
				return (line);
			}
			i++;
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	if (bytes_read < 0 || (bytes_read == 0 && (!line || !line[0])))
	{
		free(line);
		return (NULL);
	}
	return (line);
}
