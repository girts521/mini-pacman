/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:39:09 by girts             #+#    #+#             */
/*   Updated: 2024/07/27 20:07:14 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_1(t_data *data, int col, int row)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
	data->wall, col * 16, row * 16);
}

static int	is_safe_for_ghost(t_data *data, int row, int col)
{
	int	i;
	int	j;
	int	check_row;
	int	check_col;

	i = -2;
	while (i <= 2)
	{
		j = -2;
		while (j <= 2)
		{
			check_row = row + i;
			check_col = col + j;
			if (check_row >= 0 && check_row < data->row_len && \
				check_col >= 0 && check_col < data->col_len)
			{
				if (data->map[check_row][check_col] == 'P' || \
					data->map[check_row][check_col] == 'G')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	handle_0(t_data *data, int col, int row)
{
	if (data->ghost_count < data->ghosts_to_render && \
		((data->map[row][col - 1] == 'C' \
			&& is_safe_for_ghost(data, row, col)) || \
			(data->map[row][col + 1] == 'C' \
			&& is_safe_for_ghost(data, row, col))))
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
			data->blinky, col * 16, row * 16);
		data->map[row][col] = 'G';
		data->ghosts_location[data->ghost_count][0] = col;
		data->ghosts_location[data->ghost_count][1] = row;
		data->ghost_count++;
	}
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
			data->dot, col * 16, row * 16);
}

static int	find_ghost_index(t_data *data, int row, int col)
{
	int	i;

	i = 0;
	while (i < data->ghosts_to_render)
	{
		if (data->ghosts_location[i][0] == col && \
			data->ghosts_location[i][1] == row)
			return (i);
		i++;
	}
	return (-1);
}

void	handle_g(t_data *data, int col, int row)
{
	int		ghost_index;

	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
	data->blinky, col * 16, row * 16);
	ghost_index = find_ghost_index(data, row, col);
	if (ghost_index != -1 && \
		data->ghosts_location[ghost_index][3] == 1)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
			data->collectable, col * 16, row * 16);
}
