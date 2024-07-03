/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:53:48 by girts             #+#    #+#             */
/*   Updated: 2024/07/03 21:18:27 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	if_error(t_data *data, int found_player, int exit_count)
{
	if (data->collectable_count < 1)
	{
		fprintf(stderr, "Error\n");
		fprintf(stderr, "No collectables found\n");
		on_destroy(data);
	}
	if (found_player != 1)
	{
		fprintf(stderr, "Error\n");
		fprintf(stderr, "No player starting position found\n");
		on_destroy(data);
	}
	if (exit_count != 1)
	{
		fprintf(stderr, "Error\n");
		fprintf(stderr, "No exit found\n");
		on_destroy(data);
	}
}

static void	validate_cpe_loop(t_data *data, int *found_player, int *exit_count)
{
	int	row;
	int	col;

	row = 0;
	while (row < data->row_len)
	{
		col = 0;
		while (data->map[row][col] != '\0')
		{
			if (data->map[row][col] == 'C')
				data->collectable_count++;
			else if (data->map[row][col] == 'P')
			{
				data->x = col * 16;
				data->y = row * 16;
				(*found_player)++;
			}
			else if (data->map[row][col] == 'E')
				(*exit_count)++;
			col++;
		}
		row++;
	}
	data->col_len = col;
}

void	validate_cpe(t_data *data)
{
	int	found_player;
	int	exit_count;

	found_player = 0;
	exit_count = 0;
	validate_cpe_loop(data, &found_player, &exit_count);
	if_error(data, found_player, exit_count);
}

static void	load_loop(t_data *data, int fd, int *row)
{
	char	*line;
	int		length;

	line = get_next_line(fd);
	while (line)
	{
		length = ft_strlen(line);
		if (line[length - 1] == '\n')
		{
			line[length - 1] = '\0';
			length--;
		}
		data->map[*row] = malloc((length + 1) * sizeof(char));
		if (!data->map[*row])
		{
			fprintf(stderr, "Failed to allocate memory for row\n");
			on_destroy(data);
		}
		ft_strlcpy(data->map[*row], line, length + 1);
		(*row)++;
		free(line);
		line = get_next_line(fd);
	}
}

void	load_map(t_data *data, char *filename)
{
	int		fd;
	int		row;

	row = 0;
	data->map = malloc(128 * sizeof(char *));
	if (!data->map)
	{
		fprintf(stderr, "Failed to allocate memory for map\n");
		on_destroy(data);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Failed to open file\n");
		on_destroy(data);
	}
	load_loop(data, fd, &row);
	close(fd);
	data->row_len = row;
	validate_cpe(data);
}
