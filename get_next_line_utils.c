/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:22:18 by girts             #+#    #+#             */
/*   Updated: 2024/07/19 21:54:27 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_realloc(char *ptr, size_t size)
{
	char	*new_ptr;
	size_t	old_size;

	if (!ptr)
		return (malloc(size));
	old_size = 0;
	while (ptr[old_size] != '\0')
		old_size++;
	if (size <= old_size)
		return (ptr);
	new_ptr = malloc(size);
	if (!new_ptr)
	{
		free(ptr);
		return (NULL);
	}
	ft_memcpy(new_ptr, ptr, old_size);
	free(ptr);
	return (new_ptr);
}

int	handle_buffer(t_gnl *data, char	**newline_pos)
{
	data->line = ft_realloc(data->line, data->line_len + data->buffer_len + 1);
	if (!data->line)
	{
		free(data->buffer);
		return (0);
	}
	ft_memcpy(data->line + data->line_len, data->buffer, data->buffer_len);
	data->line[data->line_len + data->buffer_len] = '\0';
	if (*newline_pos)
	{
		free(data->buffer);
		return (1);
	}
	data->line_len += data->buffer_len;
	return (-1);
}
