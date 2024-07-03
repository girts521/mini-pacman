/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:48:58 by girts             #+#    #+#             */
/*   Updated: 2024/06/29 20:46:05 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void redraw_sprite(t_data *data)
{
    if(data->image)
    {
        mlx_destroy_image(data->mlx_ptr, data->image);
        data->image = NULL;
    }
    redraw(data);
    draw_sprite(data);
}