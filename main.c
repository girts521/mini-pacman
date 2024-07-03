/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 10:05:01 by girts             #+#    #+#             */
/*   Updated: 2024/07/03 14:19:11 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static int on_expose(t_data *data)
// {
//     redraw(data);
//     return (0);
// }

static void print_map(char **map, int rowlen)
{
    int row = 0;

    while (row < rowlen) {
        int col = 0;
        while (map[row][col] != '\0') {
            printf("%c", map[row][col]);
            col++;
        }
        printf("\n");
        row++;
    }
}

int main(int argc, char **argv)
{
    t_data  data;
    int     row_len;
    int     i;


    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <map_file> ghost count\n", argv[0]);
        return (1);
    }
    ft_memset(&data, 0, sizeof(t_data));
    data.img_width = 8;
    data.img_height = 8;

    data.mlx_ptr = mlx_init();
    if (!data.mlx_ptr)
    {
        fprintf(stderr, "Failed to initialize MLX\n");
        return (1);
    }
    data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 400, "hi :)");
    if (!data.win_ptr)
    {
        fprintf(stderr, "Failed to create window\n");
        free(data.mlx_ptr);
        return (1);
    }

    data.x = 0;
    data.y = 100;
    data.frame_count = 8;
    data.current_frame = 0;
    data.image = NULL;
    data.map = NULL;
    data.dot = NULL;
    data.collectable = NULL;
    data.wall = NULL;
    data.started = 0;
    data.frame_counter = 0;
    data.current_frame = 0;
    data.ghost_count = 0;
    data.game_over = 0;
    data.ghosts_frame_counter = 0;
    data.moves = 0;
    if(argc == 3)
    {
        data.ghosts_to_render = ft_atoi(argv[2]);
    }
    else
    {
        data.ghosts_to_render = 1;
    }
    
    printf("ghosts to render: %d\n", data.ghosts_to_render);

    //alloate memory for ghosts loation array [[0,0], [0,0], [0,0]]
    data.ghosts_location = malloc(sizeof(int*) * data.ghosts_to_render);
    i = 0;
    while (i < data.ghosts_to_render)
    {
        data.ghosts_location[i] = malloc(sizeof(int) * 4);
        i++;
    }

    i = 0;
    while (i < data.ghosts_to_render)
    {
        data.ghosts_location[i][0] = 0;
        data.ghosts_location[i][1] = 0;
        data.ghosts_location[i][2] = 0;
        data.ghosts_location[i][3] = 0;
        i++;
    }


    load_map(&data, argv[1], &row_len);
    validate_path(&data);
    print_map(data.map,row_len);

    

    animate_sprite(&data);


    render_map(&data);
    // Register key release hook
    mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &on_keypress, &data);

    // Register destroy hook
    mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);

    mlx_loop_hook(data.mlx_ptr, animate_loop, &data);
    // mlx_loop_hook(data.mlx_ptr, animate_move_ghost, &data);
    // mlx_hook(data.win_ptr, Expose, ExposureMask, &on_expose, &data);

    // Loop over the MLX pointer
    mlx_loop(data.mlx_ptr);
    return (1);
}