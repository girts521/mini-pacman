/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:21:38 by girts             #+#    #+#             */
/*   Updated: 2024/07/04 23:33:45 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_image(void *mlx_ptr, void **img_ptr)
{
	if (*img_ptr)
	{
		mlx_destroy_image(mlx_ptr, *img_ptr);
		*img_ptr = NULL;
	}
}

void	free_resources(t_data *data)
{
	int	i;

	i = 0;
	destroy_image(data->mlx_ptr, (void **)&data->image);
	destroy_image(data->mlx_ptr, (void **)&data->blinky);
	destroy_image(data->mlx_ptr, (void **)&data->wall);
	destroy_image(data->mlx_ptr, (void **)&data->dot);
	destroy_image(data->mlx_ptr, (void **)&data->collectable);
	destroy_image(data->mlx_ptr, (void **)&data->exit);
	if (data->map)
	{
		while (i < data->row_len && data->map[i] != NULL)
		{
			free(data->map[i]);
			data->map[i] = NULL;
			i++;
		}
		free(data->map);
		data->map = NULL;
	}
}
