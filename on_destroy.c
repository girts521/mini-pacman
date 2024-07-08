/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:46:10 by girts             #+#    #+#             */
/*   Updated: 2024/07/04 19:47:13 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_ghosts_location(t_data *data)
{
	int	i;

	i = 0;
	if (data->ghosts_location)
	{
		while (i < data->ghosts_to_render)
		{
			free(data->ghosts_location[i]);
			data->ghosts_location[i] = NULL;
			i++;
		}
		free(data->ghosts_location);
		data->ghosts_location = NULL;
	}
}

static void	destroy_window(t_data *data)
{
	if (data->win_ptr != NULL)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	if (data->mlx_ptr != NULL)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		data->mlx_ptr = NULL;
	}
}

int	on_destroy(t_data *data)
{
	data->game_over = 1;
	free_resources(data);
	free_ghosts_location(data);
	destroy_window(data);
	exit(0);
	return (0);
}
