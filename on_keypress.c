/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_keypress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:50:14 by girts             #+#    #+#             */
/*   Updated: 2024/07/04 23:24:35 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_player(t_data *data, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = (data->x / 16) + dx;
	new_y = (data->y / 16) + dy;
	if (data->map[new_y][new_x] != '1')
	{
		if (data->map[new_y][new_x] == 'C')
		{
			data->map[new_y][new_x] = '0';
			data->collected++;
		}
		if (data->map[new_y][new_x] == 'G')
			on_lose(data);
		data->x += dx * 16;
		data->y += dy * 16;
		data->moves++;
		render_map(data);
	}
	if (data->map[data->y / 16][data->x / 16] == 'E' && \
		data->collected == data->collectable_count)
		on_win(data);
}

int	on_keypress(int keysym, t_data *data)
{
	if (keysym == 65307)
	{
		on_destroy(data);
		return (1);
	}
	if (keysym == 'd')
		move_player(data, 1, 0);
	if (keysym == 'a')
		move_player(data, -1, 0);
	if (keysym == 'w')
		move_player(data, 0, -1);
	if (keysym == 's')
		move_player(data, 0, 1);
	return (0);
}
