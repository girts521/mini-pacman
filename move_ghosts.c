/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ghosts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:33:27 by girts             #+#    #+#             */
/*   Updated: 2024/07/03 12:50:48 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move_ghosts(t_data *data)
{
    int i;
    int ghost_x, ghost_y;
	int moved;

	moved = 0;
	i = 0;
    while ( i < data->ghosts_to_render)
	{
        // Calculate current grid position of the ghost
        ghost_x = data->ghosts_location[i][0];
        ghost_y = data->ghosts_location[i][1];
		int old_ghost_x = ghost_x;
        int old_ghost_y = ghost_y;


		//try previous direction first
		//right = 0, left = 1, up = 2, down = 3
		if(data->ghosts_location[i][2] == 0)
		{
			// Move ghost right if possible
        	if (data->map[ghost_y][ghost_x + 1] != '1' && ghost_x + 1 < data->col_len)
			{
            	data->ghosts_location[i][0] += 1;
				moved = 1;
				data->ghosts_location[i][2] = 0;
			}
        }
		else if(data->ghosts_location[i][2] == 1)
		{
        	// Move ghost left if possible
        	if (data->map[ghost_y][ghost_x - 1] != '1' && ghost_x - 1 >= 0)
			{
            	data->ghosts_location[i][0] -= 1;
				moved = 1;
				data->ghosts_location[i][2] = 1;
				
        	}
        }
		else if(data->ghosts_location[i][2] == 2)
		{
        // Move ghost up if possible
        	if (data->map[ghost_y - 1][ghost_x] != '1' && ghost_y - 1 >= 0)
			{
            	data->ghosts_location[i][1] -= 1;
				moved = 1;
				data->ghosts_location[i][2] = 2;
        	}
        }
		else if(data->ghosts_location[i][2] == 3)
		{
        	// Move ghost down if possible
        	if (data->map[ghost_y + 1][ghost_x] != '1' && ghost_y + 1 < data->row_len)
			{
            	data->ghosts_location[i][1] += 1;
				moved = 1;
				data->ghosts_location[i][2] = 3;
        	}
        }
		
		if (moved == 0)
		{
			// Move ghost down if possible
        	if (data->map[ghost_y + 1][ghost_x] != '1' && ghost_y + 1 < data->row_len)
			{
            	data->ghosts_location[i][1] += 1;
				data->ghosts_location[i][2] = 3;
        	}
        	// Move ghost up if possible
        	else if (data->map[ghost_y - 1][ghost_x] != '1' && ghost_y - 1 >= 0)
			{
            	data->ghosts_location[i][1] -= 1;
				data->ghosts_location[i][2] = 2;
        	}
        	// Move ghost right if possible
        	else if (data->map[ghost_y][ghost_x + 1] != '1' && ghost_x + 1 < data->col_len)
			{
            	data->ghosts_location[i][0] += 1;
				data->ghosts_location[i][2] = 0;
        	}
        	// Move ghost left if possible
        	else if (data->map[ghost_y][ghost_x - 1] != '1' && ghost_x - 1 >= 0)
			{
            	data->ghosts_location[i][0] -= 1;
				data->ghosts_location[i][2] = 1;
        	}
		}


		// Update the map with the ghost's new position
		if (data->ghosts_location[i][3] == 1)
		{
    		data->map[old_ghost_y][old_ghost_x] = 'C'; // Place collectible back
    		data->ghosts_location[i][3] = 0; // Reset the collectible flag
		}
		else
		{
    		data->map[old_ghost_y][old_ghost_x] = '0'; // Clear old position
		}

		ghost_x = data->ghosts_location[i][0];
		ghost_y = data->ghosts_location[i][1];

		if (ghost_x == data->x / 16 && ghost_y == data->y / 16)
		{
    		on_lose(data);
		}

		// Store the current content of the new position
		char current_content = data->map[ghost_y][ghost_x];

		// Set new position to 'G', but remember if it was a collectible
		data->map[ghost_y][ghost_x] = 'G';

		// If the new position is a collectible, remember this for the next move
		if (current_content == 'C')
		{
    		data->ghosts_location[i][3] = 1; // Use the 4th element of the ghost's data to remember it's on a collectible
		}

        i++;
    }
    render_map(data);
}
