/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 10:05:01 by girts             #+#    #+#             */
/*   Updated: 2024/07/03 19:04:05 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static void	print_map(char **map, int rowlen)
// {
// 	int	row;
// 	int	col;

// 	row = 0;
// 	while (row < rowlen)
// 	{
// 		col = 0;
// 		while (map[row][col] != '\0')
// 		{
// 			printf("%c", map[row][col]);
// 			col++;
// 		}
// 		printf("\n");
// 		row++;
// 	}
// }

static void	init_ghosts_locations(t_data *data)
{
	int	i;

	i = 0;
	data->ghosts_location = malloc(sizeof(int *) * data->ghosts_to_render);
	while (i < data->ghosts_to_render)
	{
		data->ghosts_location[i] = malloc(sizeof(int) * 4);
		i++;
	}
	i = 0;
	while (i < data->ghosts_to_render)
	{
		data->ghosts_location[i][0] = 0;
		data->ghosts_location[i][1] = 0;
		data->ghosts_location[i][2] = 0;
		data->ghosts_location[i][3] = 0;
		i++;
	}
}

static void	init_data(t_data *data)
{
	data->img_width = 16;
	data->img_height = 16;
	data->x = 0;
	data->y = 100;
	data->frame_count = 8;
	data->current_frame = 0;
	data->image = NULL;
	data->map = NULL;
	data->dot = NULL;
	data->collectable = NULL;
	data->wall = NULL;
	data->started = 0;
	data->frame_counter = 0;
	data->current_frame = 0;
	data->ghost_count = 0;
	data->game_over = 0;
	data->ghosts_frame_counter = 0;
	data->moves = 0;
	init_ghosts_locations(data);
}

static int	init_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		fprintf(stderr, "Failed to initialize MLX\n");
		return (0);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, 600, 400, "hi :)");
	if (!data->win_ptr)
	{
		fprintf(stderr, "Failed to create window\n");
		free(data->mlx_ptr);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s <map_file>\n", argv[0]);
		return (0);
	}
	ft_memset(&data, 0, sizeof(t_data));
	init_window(&data);
	if (argc == 3)
		data.ghosts_to_render = ft_atoi(argv[2]);
	else
		data.ghosts_to_render = 1;
	init_data(&data);
	load_map(&data, argv[1]);
	validate_path(&data);
	animate_sprite(&data);
	render_map(&data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &on_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, \
				StructureNotifyMask, &on_destroy, &data);
	mlx_loop_hook(data.mlx_ptr, animate_loop, &data);
	mlx_loop(data.mlx_ptr);
	return (1);
}
