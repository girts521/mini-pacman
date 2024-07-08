/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:17:09 by girts             #+#    #+#             */
/*   Updated: 2024/07/04 17:39:25 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_rules(t_data *data)
{
	int	i;

	if (!is_map_rectangular(data))
		error(data, "Invalid map. Map must be rectangular\n");
	if (data->map[0] && !is_wall(data->map[0]))
		error(data, "Invalid map, first line must be a wall\n");
	if (data->map[data->row_len - 1] && !is_wall(data->map[data->row_len - 1]))
		error(data, "Invalid map, last line must be a wall\n");
	i = 0;
	while (i < data->row_len)
	{
		if (data->map[i][0] != '1' || data->map[i][data->col_len - 1] != '1')
		{
			error(data, "Invalid map, first and last column must be walls\n");
			break ;
		}
		i++;
	}
}

void	init_validation(t_data *data, t_validation *val)
{
	int	i;
	int	x;
	int	y;

	val->visited = malloc(data->row_len * sizeof(char *));
	i = 0;
	while (i < data->row_len)
		val->visited[i++] = ft_calloc(data->col_len, sizeof(char));
	x = data->x / 16;
	y = data->y / 16;
	val->to_collect = data->collectable_count;
	val->exit = 1;
	val->queue = ft_lstnew(&data->map[y][x]);
	val->queue->x = x;
	val->queue->y = y;
	val->visited[y][x] = '1';
}

void	check_direction(t_data *data, t_validation *val, int x, int y)
{
	char	current_content;

	if (x >= 0 && x < data->col_len && y >= 0 && y < data->row_len && \
		data->map[y][x] != '1' && val->visited[y][x] != '1')
	{
		current_content = data->map[y][x];
		if ((current_content) == 'C' && val->to_collect > 0)
			val->to_collect--;
		else if ((current_content) == 'E' && val->exit > 0)
			val->exit--;
		val->visited[y][x] = '1';
		add_to_queue(&val->queue, data->map[y][x], x, y);
	}
}

void	check_adjacent(t_data *data, t_validation *val, int x, int y)
{
	check_direction(data, val, x, y - 1);
	check_direction(data, val, x, y + 1);
	check_direction(data, val, x - 1, y);
	check_direction(data, val, x + 1, y);
}

void	validate_path(t_data *data)
{
	t_validation	val;
	t_list			*current;

	check_rules(data);
	init_validation(data, &val);
	while (ft_lstsize(val.queue) > 0)
	{
		current = ft_lst_remove_last(&val.queue);
		check_adjacent(data, &val, current->x, current->y);
	}
	if (val.to_collect > 0 || val.exit > 0)
		error(data, "Not all collectibles and exits can be reached.\n");
	free_visited(&val, data->row_len);
}
