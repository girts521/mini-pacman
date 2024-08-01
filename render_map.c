/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:52:07 by girts             #+#    #+#             */
/*   Updated: 2024/07/27 20:11:23 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	load_image(t_data *data, void **img_ptr, char *path)
{
	int		height;
	int		width;

	height = 16;
	width = 16;
	if (*img_ptr != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, *img_ptr);
		*img_ptr = NULL;
	}
	*img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, path, &width, &height);
	if (!(*img_ptr))
	{
		fprintf(stderr, "Failed to load image: %s\n", path);
		return (0);
	}
	return (1);
}

static void	load_all_images(t_data *data)
{
	load_image(data, &(data->wall), "textures/test.xpm");
	if (!data->wall)
		on_destroy(data);
	load_image(data, &(data->blinky), "textures/ghosts/blinky.xpm");
	if (!data->blinky)
		on_destroy(data);
	load_image(data, &(data->dot), "textures/other/dot.xpm");
	if (!data->dot)
		on_destroy(data);
	load_image(data, &(data->exit), "textures/other/E.xpm");
	if (!data->exit)
		on_destroy(data);
	load_image(data, &(data->collectable), "textures/other/strawberry.xpm");
	if (!data->collectable)
		on_destroy(data);
}

static void	iterate_col(t_data *data, int row)
{
	int		col;

	col = 0;
	while (data->map[row][col] != '\0')
	{
		if (data->map[row][col] == '1')
			handle_1(data, col, row);
		else if (data->map[row][col] == '0')
			handle_0(data, col, row);
		else if (data->map[row][col] == 'G')
			handle_g(data, col, row);
		else if (data->map[row][col] == 'P' && data->started == 0)
			handle_p(data, col, row);
		else if (data->map[row][col] == 'C')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
				data->collectable, col * 16, row * 16);
		else if (data->map[row][col] == 'E')
			handle_e(data, col, row);
		col++;
	}
}

//free_resources causes segfault
void	render_map(t_data *data)
{
	int		row;

	row = 0;
	load_all_images(data);
	while (row < data->row_len)
		iterate_col(data, row++);
	display_moves(data);
}
