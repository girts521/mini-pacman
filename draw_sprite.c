/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:47:38 by girts             #+#    #+#             */
/*   Updated: 2024/07/03 13:10:59 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void draw_sprite(t_data *data)
{
    if (data->image != NULL)
    {
        mlx_destroy_image(data->mlx_ptr, data->image);
        data->image = NULL;
    }

    // animate_sprite(data);
    // data->image = mlx_xpm_file_to_image(data->mlx_ptr, "textures/pacman.xpm", &data->img_width, &data->img_height);
    
    if (!data->image)
    {
        // fprintf(stderr, "Failed to load image in draw_sprite\n");
        // mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        // mlx_destroy_display(data->mlx_ptr);
        // free(data->mlx_ptr);
        // return ;
        animate_sprite(data);
    }
    
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image, data->x, data->y);
    printf("Image loaded successfully\n");

}