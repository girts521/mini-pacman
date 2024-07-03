/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:17:09 by girts             #+#    #+#             */
/*   Updated: 2024/07/03 22:42:38 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	print_visited(char **visited, int rowlen, int collen)
// {
// 	int	row;
// 	int	col;

// 	row = 0;
// 	while (row < rowlen)
// 	{
// 		col = 0;
// 		while (col < collen)
// 		{
// 			if (visited[row][col] == '\0')
// 				printf("0");
// 			else
// 				printf("%c", visited[row][col]);
// 			col++;
// 		}
// 		printf("\n");
// 		row++;
// 	}
// }

static int	is_wall(char *line)
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

static int	is_map_rectangular(t_data *data)
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

void check_rules(t_data *data)
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

int	validate_path(t_data *data)
{
	t_list	*queue;
	int		x;
	int		y;
	t_list	*current_node;
	int		to_collect;
	int		exit;
	t_list	*right_node;
	t_list	*left_node;
	t_list	*up_node;
	t_list	*down_node;
	char	current_content;
	char	**visited;
	int		i;

	check_rules(data);
	visited = malloc(data->row_len * sizeof(char *));
	i = 0;
	while (i < data->row_len)
		visited[i++] = ft_calloc(data->col_len, sizeof(char));
	x = data->x / 16;
	y = data->y / 16;
	to_collect = data->collectable_count;
	exit = 1;
	current_content = data->map[y][x];
	queue = ft_lstnew(&current_content);
	queue->x = x;
	queue->y = y;
	visited[y][x] = '1';
	while (ft_lstsize(queue) > 0)
	{
		current_node = ft_lst_remove_last(&queue);
		x = current_node->x;
		y = current_node->y;
		if (y > 0 && data->map[y - 1][x] != '1' && visited[y - 1][x] != '1'\
				&& visited[y - 1][x] != 'C')
		{
			current_content = data->map[y - 1][x];
			if ((current_content) == 'C' && to_collect > 0)
			{
				to_collect--;
				visited[y - 1][x] = 'C';
			}
			else if ((current_content) == 'E' && exit > 0)
			{
				exit--;
				visited[y - 1][x] = '1';
			}
			else
				visited[y - 1][x] = '1';
			up_node = ft_lstnew(&current_content);
			up_node->x = x;
			up_node->y = y - 1;
			ft_lstadd_front(&queue, up_node);
		}
		if (y < data->row_len - 1 && data->map[y + 1][x] != '1' && \
				visited[y + 1][x] != '1' && visited[y + 1][x] != 'C')
		{
			current_content = data->map[y + 1][x];
			if ((current_content) == 'C' && to_collect > 0)
			{
				to_collect--;
				visited[y + 1][x] = 'C';
			}
			else if ((current_content) == 'E' && exit > 0)
			{
				visited[y + 1][x] = '1';
				exit--;
			}
			else
				visited[y + 1][x] = '1';
			down_node = ft_lstnew(&current_content);
			down_node->x = x;
			down_node->y = y + 1;
			ft_lstadd_front(&queue, down_node);
		}
		if (x > 0 && data->map[y][x - 1] != '1' && \
			visited[y][x - 1] != '1' && visited[y][x - 1] != 'C')
		{
			current_content = data->map[y][x - 1];
			if ((current_content) == 'C' && to_collect > 0)
			{
				to_collect--;
				visited[y][x - 1] = 'C';
			}
			else if ((current_content) == 'E' && exit > 0)
			{
				exit--;
				visited[y][x - 1] = '1';
			}
			else
				visited[y][x - 1] = '1';
			left_node = ft_lstnew(&current_content);
			left_node->x = x - 1;
			left_node->y = y;
			ft_lstadd_front(&queue, left_node);
		}
		if (x < data->col_len - 1 && data->map[y][x + 1] != '1' \
				&& visited[y][x + 1] != '1' && visited[y][x + 1] != 'C')
		{
			current_content = data->map[y][x + 1];
			if ((current_content) == 'C' && to_collect > 0)
			{
				to_collect--;
				visited[y][x + 1] = 'C';
			}
			else if ((current_content) == 'E' && exit > 0)
			{
				exit--;
				visited[y][x + 1] = '1';
			}
			else
				visited[y][x + 1] = '1';
			right_node = ft_lstnew(&current_content);
			right_node->x = x + 1;
			right_node->y = y;
			ft_lstadd_front(&queue, right_node);
		}
	}
	if (to_collect == 0 && exit == 0)
		return (1);
	else
	{
		error(data, "Not all collectibles and exits can be reached.\n");
		return (0);
	}
}
