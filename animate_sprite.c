/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 22:23:49 by girts             #+#    #+#             */
/*   Updated: 2024/09/04 18:17:01 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	cleanup(char **file, char **str_num, t_data *data, int error_code)
{
	if (*file)
		free(*file);
	if (*str_num)
		free(*str_num);
	if (error_code == 1)
		error(data, "Failed to load image in animate_sprite");
}

void	animate_sprite(t_data *data)
{
	char	*str_num;
	char	*file;

	if (data->image)
	{
		mlx_destroy_image(data->mlx_ptr, data->image);
		data->image = NULL;
	}
	if (data->current_frame == 3)
		data->current_frame = 0;
	data->current_frame++;
	str_num = ft_itoa(data->current_frame);
	file = malloc(ft_strlen("textures/pacman-right/pacman") \
			+ ft_strlen(str_num) + 5);
	if (!file)
		cleanup(&file, &str_num, data, 1);
	ft_strlcpy(file, "textures/pacman-right/pacman", \
				ft_strlen("textures/pacman-right/pacman") + 1);
	ft_strlcat(file, str_num, ft_strlen(file) + ft_strlen(str_num) + 1);
	ft_strlcat(file, ".xpm", ft_strlen(file) + 5);
	data->image = mlx_xpm_file_to_image(data->mlx_ptr, file, \
					&data->img_width, &data->img_height);
	if (!data->image)
		cleanup(&file, &str_num, data, 1);
	cleanup(&file, &str_num, data, 0);
}

int	animate_loop(t_data *data)
{
	data->frame_counter++;
	if (data->frame_counter >= 10000)
	{
		data->ghosts_frame_counter++;
		animate_sprite(data);
		move_ghosts(data);
		data->frame_counter = 0;
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
								data->image, data->x, data->y);
	}
	return (0);
}
