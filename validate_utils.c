/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:42:24 by girts             #+#    #+#             */
/*   Updated: 2024/07/04 11:46:26 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	is_map_rectangular(t_data *data)
{
	int	first_row_length;
	int	i;

	i = 1;
	first_row_length = ft_strlen(data->map[0]);
	while (i < data->row_len)
	{
		if (ft_strlen(data->map[i]) != first_row_length)
			return (0);
		i++;
	}
	return (1);
}

void	add_to_queue(t_list **queue, char current_content, int x, int y)
{
	t_list	*new;

	new = ft_lstnew(&current_content);
	new->x = x;
	new->y = y;
	ft_lstadd_back(queue, new);
}

void	free_visited(t_validation *val, int row_len)
{
	int	i;

	i = 0;
	while (i < row_len)
	{
		free(val->visited[i]);
		i++;
	}
	free(val->visited);
}
