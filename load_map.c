/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:53:48 by girts             #+#    #+#             */
/*   Updated: 2024/07/03 17:07:09 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



void load_map(t_data *data, char *filename, int *row_len)
{
    char    *line;
    int     fd;
    int     row;
    int     j;
    int     col;
    int     found_player;
    int     exit_count;

    row = 0;
    j = 0;
    found_player = 0;
    exit_count = 0;
    data->map = malloc(128 * sizeof(char *));
    if (!data->map) {
        fprintf(stderr, "Failed to allocate memory for map\n");
        return ;
    }
    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        fprintf(stderr, "Failed to open file\n");
        return ;
    }
    printf("File %s opened successfully\n", filename);

    line = get_next_line(fd);
    while (line)
    {
        int length = ft_strlen(line);
        if (line[length - 1] == '\n') {
            line[length - 1] = '\0';
            length--;
        }

        data->map[row] = malloc((length + 1) * sizeof(char)); // Allocate memory for the row with null terminator
        if (!data->map[row]) {
            fprintf(stderr, "Failed to allocate memory for row\n");
            
            while (j < row) {
                free(data->map[j]);
                j++;
            }
            free(data->map);
            return ;
        }

        ft_strlcpy(data->map[row], line, length + 1); // Copy line to map
        row++;
        free(line);
        line = get_next_line(fd);
    }

    close(fd);
    *row_len = row; // Set the row length
    data->row_len = row;

    row = 0;
    while (row < data->row_len)
    {
        col = 0;
        while (data->map[row][col] != '\0')
        {
            // printf("looking for C:%c\n", data->map[row][col]);
            if (data->map[row][col] == 'C')
            {
                data->collectable_count++;
            }
            else if (data->map[row][col] == 'P')
            {
                data->x = col * 16;
                data->y = row * 16;
                found_player++;
            }
            else if (data->map[row][col] == 'E')
            {
                exit_count++;
            }
            col++;
        }
        row++;
    }
    data->col_len = col;
    printf("map loaded successfully\n");
    if (data->collectable_count < 1)
    {
        fprintf(stderr,"Error\n");
        fprintf(stderr, "No collectables found\n");
        on_destroy(data);
        return ;
    }
    if (found_player != 1)
    {
        fprintf(stderr,"Error\n");
        fprintf(stderr, "No player starting position found\n");
        on_destroy(data);
        return ;
    }
    if (exit_count != 1)
    {
        fprintf(stderr,"Error\n");
        fprintf(stderr, "No exit found\n");
        on_destroy(data);
        return ;
    }
    
}