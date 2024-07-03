/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 20:10:23 by girts             #+#    #+#             */
/*   Updated: 2024/07/03 22:14:16 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <unistd.h>
#include "get_next_line.h"
#include <fcntl.h>
#include "libft.h"
#include "math.h"

typedef struct s_data {
    void *mlx_ptr;
    void *win_ptr;
    void *image;
    void **frames; // Array to hold each frame
    int img_width;
    int img_height;
    int x;
    int y;
    int frame_count;
    int current_frame;
    int frame_counter;
    char **map;
    void *wall;
    void *dot;
    void *collectable;
    void *exit;
    void *blinky;
	int **ghosts_location;
    int ghost_count;
    int ghosts_to_render;
	int ghosts_frame_counter;
    int row_len;
    int col_len;
    int started;
    int end;
    int collectable_count;
    int collected;
	int game_over;
    int moves;
} t_data;

int on_destroy(t_data *data);
void draw_sprite(t_data *data);
void redraw_sprite(t_data *data);
int on_keypress(int keysym, t_data *data);
void redraw(t_data *data);
void render_map(t_data *data);
void load_map(t_data *data, char *filename);
void animate_sprite(t_data *data);
int animate_loop(t_data *data);
void on_win(t_data *data);
void on_lose(t_data *data);
void move_ghosts(t_data *data);
int animate_move_ghost(t_data *data);
int validate_path(t_data *data);
t_list	*ft_lst_remove_last(t_list **lst);
void error(t_data *data, char *str);

#endif
