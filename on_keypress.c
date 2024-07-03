/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_keypress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:50:14 by girts             #+#    #+#             */
/*   Updated: 2024/07/02 09:48:27 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int on_keypress(int keysym, t_data *data)
{
    (void)data;
    printf("Pressed key: %d\n", keysym);
    if(keysym == 65307)
    {
        on_destroy(data);
        return (1);
    }
    if (keysym == 'q')
    {
        printf("q pressed\n");
        printf("collected: %d\n", data->collected);
        printf("collactables: %d\n", data->collectable_count);
        redraw(data);
        redraw_sprite(data);
        return (1);
    }
    if (keysym == 'k')
    {
        on_win(data);
    }
    if (keysym == 'd')
    {
        printf("collected: %d and collactables: %d\n", data->collected, data->collectable_count);
        if(data->map[data->y / 16][(data->x / 16) + 1] != '1')
        {
            if(data->map[data->y / 16][(data->x / 16) + 1] == 'C')
            {
                data->map[data->y / 16][(data->x / 16) + 1] = '0';
                data->collected++;
                render_map(data);
            }
            if (data->map[data->y / 16][(data->x / 16) + 1] == 'G')
            {
                on_lose(data);
            }
            data->x += 16;
            data->moves++;
            redraw_sprite(data);
        }
        if(data->map[data->y / 16][(data->x / 16)] == 'E' && data->collected == data->collectable_count)
        {
            on_win(data);
        }
    }
    if (keysym == 'a')
    {
        if(data->map[data->y / 16][(data->x / 16) - 1] != '1')
        {
            if(data->map[data->y / 16][(data->x / 16) - 1] == 'C')
            {
                data->map[data->y / 16][(data->x / 16) - 1] = '0';
                data->collected++;
                render_map(data);
            }
            if(data->map[data->y / 16][(data->x / 16) - 1] == 'G')
            {
                on_lose(data);
            }
            data->x -= 16;
            data->moves++;
            redraw_sprite(data);
        }
        if(data->map[data->y / 16][(data->x / 16)] == 'E' && data->collected == data->collectable_count)
        {
            on_win(data);
        }
    }
    if (keysym == 'w')
    {
        if(data->map[(data->y / 16) - 1][data->x / 16] != '1')
        {
            if(data->map[(data->y / 16) - 1][data->x / 16] == 'C')
            {
                data->map[(data->y / 16) - 1][data->x / 16] = '0';
                data->collected++;
                render_map(data);
            }
            if(data->map[(data->y / 16) - 1][data->x / 16] == 'G')
            {
                on_lose(data);
            }
            data->y -= 16;
            data->moves++;
            redraw_sprite(data);
        }
        if(data->map[data->y / 16][(data->x / 16)] == 'E' && data->collected == data->collectable_count)
        {
            on_win(data);
        }
    }
    if (keysym == 's')
    {
        if(data->map[(data->y / 16) + 1][data->x / 16] != '1')
        {
            if(data->map[(data->y / 16) + 1][data->x / 16] == 'C')
            {
                data->map[(data->y / 16) + 1][data->x / 16] = '0';
                data->collected++;
                render_map(data);
            }
            if(data->map[(data->y / 16) + 1][data->x / 16] == 'G')
            {
                on_lose(data);
            }
            data->y += 16;
            data->moves++;
            redraw_sprite(data);
        }
        if(data->map[data->y / 16][(data->x / 16)] == 'E' && data->collected == data->collectable_count)
        {
            printf("collected: %d and collactables: %d\n", data->collected, data->collectable_count);
            on_win(data);
        }
    }
    printf("moves: %d\n", data->moves);
    return (0);
}