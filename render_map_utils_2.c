/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 20:06:46 by girts             #+#    #+#             */
/*   Updated: 2024/07/28 19:41:45 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_p(t_data *data, int col, int row)
{
	data->x = col * 16;
	data->y = row * 16;
	draw_sprite(data);
	data->map[row][col] = '0';
	data->started = 1;
}

void	handle_e(t_data *data, int col, int row)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		data->dot, col * 16, row * 16);
	if (data->collected == data->collectable_count)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
			data->exit, col * 16, row * 16);
}

void	handle_str(t_data *data)
{
	char	*moves_str;
	char	*moves_num;

	moves_num = ft_itoa(data->moves);
	moves_str = malloc(ft_strlen(moves_num) \
						+ ft_strlen(" moves") + 1);
	if (moves_str)
	{
		ft_strlcpy(moves_str, moves_num, \
					ft_strlen(moves_num) + 1);
		ft_strlcat(moves_str, " moves", ft_strlen(moves_num) + 6);
	}
	mlx_string_put(data->mlx_ptr, data->win_ptr, 500, \
		((data->row_len - 1) * 16) + 50, 0xFFFFFF, moves_str);
	free(moves_str);
	free(moves_num);
}

void	display_moves(t_data *data)
{
	void	*blank_image;
	int		*image_data;
	int		height;
	int		width;
	int		i;

	height = 16;
	width = 16;
	blank_image = mlx_new_image(data->mlx_ptr, 100, 20);
	image_data = (int *)mlx_get_data_addr(blank_image, &width, &height, &width);
	i = 0;
	while (i < 100 * 20)
		image_data[i++] = 0x000000;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
		blank_image, 500, ((data->row_len - 1) * 16) + 40);
	handle_str(data);
	mlx_destroy_image(data->mlx_ptr, blank_image);
}
