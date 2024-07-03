/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:52:07 by girts             #+#    #+#             */
/*   Updated: 2024/07/03 13:38:39 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int is_safe_for_ghost(t_data *data, int row, int col) {
    int i = -2;
    while (i <= 2) {
        int j = -2;
        while (j <= 2) {
            int check_row = row + i;
            int check_col = col + j;
            
            // Ensure we're within map boundaries
            if (check_row >= 0 && check_row < data->row_len && 
                check_col >= 0 && check_col < data->col_len) {
                // Check for player or existing ghost
                if (data->map[check_row][check_col] == 'P' || 
                    data->map[check_row][check_col] == 'G') {
                    return 0; // Not safe
                }
            }
            j++;
        }
        i++;
    }
    return 1; // Safe
}

static int find_ghost_index(t_data *data, int row, int col)
{
    for (int i = 0; i < data->ghosts_to_render; i++)
    {
        if (data->ghosts_location[i][0] == col && data->ghosts_location[i][1] == row)
        {
            return i;
        }
    }
    return -1;
}

void render_map(t_data *data)
{
    int row = 0;
    // int i;
    int height = 16;
    int width = 16;
    char *moves_str;


    // Check if wall image already exists, if yes, destroy it.
    if (data->wall != NULL)
    {
        mlx_destroy_image(data->mlx_ptr, data->wall);
        data->wall = NULL;
    }
    data->wall = mlx_xpm_file_to_image(data->mlx_ptr, "textures/test.xpm", &width, &height);
    if (!data->wall)
    {
        fprintf(stderr, "Failed to load wall image\n");
        return;
    }

	if (data->blinky != NULL)
    {
        mlx_destroy_image(data->mlx_ptr, data->blinky);
        data->blinky = NULL;
    }
    data->blinky = mlx_xpm_file_to_image(data->mlx_ptr, "textures/ghosts/blinky.xpm", &width, &height);
    if (!data->blinky)
    {
        fprintf(stderr, "Failed to load blinky image\n");
        return;
    }

	if (data->dot != NULL)
    {
        mlx_destroy_image(data->mlx_ptr, data->dot);
        data->dot = NULL;
    }
    data->dot = mlx_xpm_file_to_image(data->mlx_ptr, "textures/other/dot.xpm", &width, &height);
    if (!data->dot)
    {
        fprintf(stderr, "Failed to load dot image\n");
        return;
    }

	///
	if (data->exit != NULL)
    {
        mlx_destroy_image(data->mlx_ptr, data->exit);
        data->exit = NULL;
    }
    data->exit = mlx_xpm_file_to_image(data->mlx_ptr, "textures/other/E.xpm", &width, &height);
    if (!data->exit)
    {
        fprintf(stderr, "Failed to load dot image\n");
        return;
    }

	if (data->collectable != NULL)
    {
		// printf("Destroying collectable image\n");
        mlx_destroy_image(data->mlx_ptr, data->collectable);
        data->collectable = NULL;
    }
	// printf("Loading collectable image\n");
    data->collectable = mlx_xpm_file_to_image(data->mlx_ptr, "textures/other/strawberry.xpm", &width, &height);
    if (!data->collectable)
    {
        fprintf(stderr, "Failed to load collectable image\n");
        return;
    }

    while (row < data->row_len) {
        int col = 0;
        // printf("Processing row %d\n", row);
        while (data->map[row][col] != '\0')
        {
            // printf("Processing col %d\n", col);
            if (data->map[row][col] == '1')
            {
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall, col * 16, row * 16);
            }
            else if (data->map[row][col] == '0')
            {
				if (data->ghost_count < data->ghosts_to_render && 
                    ((data->map[row][col - 1] == 'C' && is_safe_for_ghost(data, row, col)) || 
                     (data->map[row][col + 1] == 'C' && is_safe_for_ghost(data, row, col))))
                {
					printf("adding a ghost\n");
					mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->blinky, col * 16, row * 16);
					data->map[row][col] = 'G';
					data->ghosts_location[data->ghost_count][0] = col;
					data->ghosts_location[data->ghost_count][1] = row;
					data->ghost_count++;
                    printf("Ghost added count: %d\n", data->ghost_count);
				}
				else
				{
					mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->dot, col * 16, row * 16);
				}
            }
			else if (data->map[row][col] == 'G')
			{
        		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->blinky, col * 16, row * 16);
        
        		// If the ghost is on a collectible, render the collectible as well
        		int ghost_index = find_ghost_index(data, row, col);
        		if (ghost_index != -1 && data->ghosts_location[ghost_index][3] == 1)
        		{
            		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->collectable, col * 16, row * 16);
        		}
			}
            else if (data->map[row][col] == 'P' && data->started == 0)
            {
				data->x = col * 16;
				data->y = row * 16;
				draw_sprite(data);
				data->map[row][col] = '0';
				data->started = 1;
            }
			else if (data->map[row][col] == 'C')
            {
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->collectable, col * 16, row * 16);
            }
			else if (data->map[row][col] == 'E')
            {
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->dot, col * 16, row * 16);
				if(data->collected == data->collectable_count)
				{
					mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit, col * 16, row * 16);
				}
            }
            col++;
        }
        row++;
        // printf("Finished processing rows\n");
    }
    // printf("here!\n");

    void *blank_image = mlx_new_image(data->mlx_ptr, 100, 20); // Adjust size as needed
    int *image_data = (int *)mlx_get_data_addr(blank_image, &width, &height, &width);
    for (int i = 0; i < 100 * 20; i++)
        image_data[i] = 0x000000; // Fill with black color
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, blank_image, 500, ((data->row_len - 1) * 16) + 40);

    char *moves_num = ft_itoa(data->moves);
    moves_str = malloc(ft_strlen(moves_num) + ft_strlen(" moves") +1);
    if (moves_str)
    {
        ft_strlcpy(moves_str, moves_num, ft_strlen(moves_num) + 1);
        ft_strlcat(moves_str, " moves", ft_strlen(moves_num) + 6);
    }
    free(moves_num);
    ft_strlcat(moves_str, " moves", ft_strlen(ft_itoa(data->moves)) + 6);
    mlx_string_put(data->mlx_ptr, data->win_ptr, 500, ((data->row_len - 1) * 16) + 50, 0xFFFFFF, moves_str);
    free(moves_str);
    mlx_destroy_image(data->mlx_ptr, blank_image);
    
}