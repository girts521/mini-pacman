/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_win.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 10:20:30 by girts             #+#    #+#             */
/*   Updated: 2024/07/04 18:15:17 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	on_win(t_data *data)
{
	int	block_size;
	int	counter;
	int	map_bottom;
	int	sprite_y;

	counter = 0;
	block_size = 16;
	map_bottom = (data->row_len - 1) * block_size;
	sprite_y = data->y;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 250, \
					map_bottom + 50, 0xFFFFFF, "You, Won!");
	while (sprite_y + block_size > 0)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
								data->dot, data->x, sprite_y);
		sprite_y--;
		if (sprite_y + block_size > 0)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
									data->image, data->x, sprite_y);
		mlx_do_sync(data->mlx_ptr);
		while (counter < 30000000)
			counter++;
		counter = 0;
	}
	on_destroy(data);
}
