/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ghosts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:33:27 by girts             #+#    #+#             */
/*   Updated: 2024/07/04 23:04:21 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_ghosts_location(t_data *data, int direction, int i)
{
	if (direction == 0)
		data->ghosts_location[i][0] += 1;
	else if (direction == 1)
		data->ghosts_location[i][0] -= 1;
	else if (direction == 2)
		data->ghosts_location[i][1] -= 1;
	else if (direction == 3)
		data->ghosts_location[i][1] += 1;
	data->ghosts_location[i][2] = direction;
}

static void	try_move_ghost(t_data *data, int i, int dir, int *moved)
{
	int	x;
	int	y;

	x = data->ghosts_location[i][0];
	y = data->ghosts_location[i][1];
	if (dir == 0 && data->map[y][x + 1] != '1' && x + 1 < data->col_len)
	{
		update_ghosts_location(data, dir, i);
		*moved = 1;
	}
	if (dir == 1 && data->map[y][x - 1] != '1' && x - 1 >= 0)
	{
		update_ghosts_location(data, dir, i);
		*moved = 1;
	}
	else if (dir == 2 && data->map[y - 1][x] != '1' && y - 1 >= 0)
	{
		update_ghosts_location(data, dir, i);
		*moved = 1;
	}
	else if (dir == 3 && data->map[y + 1][x] != '1' && y + 1 < data->row_len)
	{
		update_ghosts_location(data, dir, i);
		*moved = 1;
	}
}

static void	try_alternate_moves(t_data *data, int i)
{
	int	ghost_x;
	int	ghost_y;

	ghost_x = data->ghosts_location[i][0];
	ghost_y = data->ghosts_location[i][1];
	if (data->map[ghost_y + 1][ghost_x] != '1' && ghost_y + 1 < data->row_len)
		update_ghosts_location(data, 3, i);
	else if (data->map[ghost_y - 1][ghost_x] != '1' && ghost_y - 1 >= 0)
		update_ghosts_location(data, 2, i);
	else if (data->map[ghost_y][ghost_x + 1] != '1' \
				&& ghost_x + 1 < data->col_len)
		update_ghosts_location(data, 0, i);
	else if (data->map[ghost_y][ghost_x - 1] != '1' && ghost_x - 1 >= 0)
		update_ghosts_location(data, 1, i);
}

static void	update_map(t_data *data, int i, int old_ghost_x, int old_ghost_y)
{
	int		ghost_x;
	int		ghost_y;
	char	current_content;

	ghost_x = data->ghosts_location[i][0];
	ghost_y = data->ghosts_location[i][1];
	if (data->ghosts_location[i][3] == 1)
	{
		data->map[old_ghost_y][old_ghost_x] = 'C';
		data->ghosts_location[i][3] = 0;
	}
	else
		data->map[old_ghost_y][old_ghost_x] = '0';
	if (ghost_x == data->x / 16 && ghost_y == data->y / 16)
		on_lose(data);
	current_content = data->map[ghost_y][ghost_x];
	data->map[ghost_y][ghost_x] = 'G';
	if (current_content == 'C')
		data->ghosts_location[i][3] = 1;
}

void	move_ghosts(t_data *data)
{
	int	i;
	int	old_ghost_x;
	int	old_ghost_y;
	int	moved;

	i = 0;
	while (i < data->ghosts_to_render)
	{
		old_ghost_x = data->ghosts_location[i][0];
		old_ghost_y = data->ghosts_location[i][1];
		moved = 0;
		try_move_ghost(data, i, data->ghosts_location[i][2], &moved);
		if (moved == 0)
			try_alternate_moves(data, i);
		update_map(data, i, old_ghost_x, old_ghost_y);
		i++;
	}
	render_map(data);
}
