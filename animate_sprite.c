/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 22:23:49 by girts             #+#    #+#             */
/*   Updated: 2024/07/03 13:10:36 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void animate_sprite(t_data *data)
{
    if(data->image)
    {
        mlx_destroy_image(data->mlx_ptr, data->image);
        data->image = NULL;
    }
    
    if (data->current_frame == 3)
        data->current_frame = 0;
    data->current_frame++;
    
    char *str_num = ft_itoa(data->current_frame);
    // printf("str_num: %s\n", str_num);
    
    char *file = malloc(ft_strlen("textures/pacman-right/pacman") + ft_strlen(str_num) + 5);
    if (!file)
    {
        free(str_num);
        return;  // Handle malloc failure
    }
    
    ft_strlcpy(file, "textures/pacman-right/pacman", ft_strlen("textures/pacman-right/pacman") + 1);
    ft_strlcat(file, str_num, ft_strlen(file) + ft_strlen(str_num) + 1);
    ft_strlcat(file, ".xpm", ft_strlen(file) + 5);
    
    // printf("file: %s\n", file);
    
    data->image = mlx_xpm_file_to_image(data->mlx_ptr, file, &data->img_width, &data->img_height);
    if (!data->image)
	// TODO: itoa fails and gives '-' sometimes for some reason
        printf("Failed to load image in animate_sprite: %s and num: %s and frame: %d\n", file, str_num, data->current_frame);
    
    free(file);
    free(str_num);
}

int animate_loop(t_data *data)
{
	data->frame_counter++;
	// printf("Frame counter: %d\n", data->frame_counter);
    // Animate every 30 frames (adjust this number to change animation speed)
    if (data->frame_counter >= 5000)
    {
		data->ghosts_frame_counter++;
        animate_sprite(data);
		move_ghosts(data);
        data->frame_counter = 0;  // Reset the counter
        
        // Redraw the sprite at its current position
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image, data->x, data->y);
    }

    return (0);
}