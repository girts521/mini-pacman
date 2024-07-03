/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:51:28 by girts             #+#    #+#             */
/*   Updated: 2024/07/01 11:00:03 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void redraw(t_data *data)
{    
    // int i;

    // Clear the window
    // mlx_clear_window(data->mlx_ptr, data->win_ptr);

    printf("Redrawing window\n");
       // Debug information
    if (!data) {
        printf("data pointer is NULL\n");
        return;
    }
    // Destroy all images here (assuming data->image contains the previous image buffer)
    if (data->image != NULL)
    {
        printf("Destroying image\n");
        mlx_destroy_image(data->mlx_ptr, data->image);
        data->image = NULL;
    }

    if (data->blinky != NULL)
    {
        mlx_destroy_image(data->mlx_ptr, data->blinky);
        data->blinky = NULL;
    }

    if (data->wall != NULL)
    {
        mlx_destroy_image(data->mlx_ptr, data->wall);
        data->wall = NULL;
    }

    if (data->dot != NULL)
    {
        mlx_destroy_image(data->mlx_ptr, data->dot);
        data->dot = NULL;
    }
    if (data->collectable != NULL)
    {
        mlx_destroy_image(data->mlx_ptr, data->collectable);
        data->collectable = NULL;
    }
    if (data->exit != NULL)
    {
        mlx_destroy_image(data->mlx_ptr, data->exit);
        data->exit = NULL;
    }
    // Assuming render_map initializes data->map and images
    render_map(data);

    // Draw sprite (this likely recreates data->image)
    // draw_sprite(data);
}