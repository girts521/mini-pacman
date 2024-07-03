/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:46:10 by girts             #+#    #+#             */
/*   Updated: 2024/07/01 22:39:47 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int on_destroy(t_data *data)
{
    int i;

    i = 0;

    data->game_over = 1;
    if (data->image)
    {
        mlx_destroy_image(data->mlx_ptr, data->image);
        data->image = NULL;
    }

    if (data->blinky)
    {
        mlx_destroy_image(data->mlx_ptr, data->blinky);
        data->blinky = NULL;
    }

    if (data->wall)
    {
        mlx_destroy_image(data->mlx_ptr, data->wall);
        data->wall = NULL;
    }

    if (data->dot)
    {
        mlx_destroy_image(data->mlx_ptr, data->dot);
        data->dot = NULL;
    }

    if (data->collectable)
    {
        mlx_destroy_image(data->mlx_ptr, data->collectable);
        data->collectable = NULL;
    }

    if (data->exit)
    {
        mlx_destroy_image(data->mlx_ptr, data->exit);
        data->exit = NULL;
    }

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

    ////free memory for ghosts_loation array [[0,0], [0,0], [0,0]]
    if (data->ghosts_location)
    {
        while (i < 3)
        {
            free(data->ghosts_location[i]);
            data->ghosts_location[i] = NULL;
            i++;
        }
        free(data->ghosts_location);
        data->ghosts_location = NULL;
    }


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
    exit(0);
    return (0);
}