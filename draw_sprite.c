/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:47:38 by girts             #+#    #+#             */
/*   Updated: 2024/07/04 18:32:44 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_sprite(t_data *data)
{
	if (data->image != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, data->image);
		data->image = NULL;
	}
	if (!data->image)
		animate_sprite(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
							data->image, data->x, data->y);
}
