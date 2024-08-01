/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 20:10:23 by girts             #+#    #+#             */
/*   Updated: 2024/07/28 19:26:49 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <unistd.h>
# include "get_next_line.h"
# include <fcntl.h>
# include "libft.h"
# include "math.h"

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*image;
	void	**frames;
	int		img_width;
	int		img_height;
	int		x;
	int		y;
	int		frame_count;
	int		current_frame;
	int		frame_counter;
	char	**map;
	void	*wall;
	void	*dot;
	void	*collectable;
	void	*exit;
	void	*blinky;
	int		**ghosts_location;
	int		ghost_count;
	int		ghosts_to_render;
	int		ghosts_frame_counter;
	int		row_len;
	int		col_len;
	int		started;
	int		end;
	int		collectable_count;
	int		collected;
	int		game_over;
	int		moves;
}	t_data;

typedef struct s_validation
{
	t_list	*queue;
	char	**visited;
	int		to_collect;
	int		exit;
}	t_validation;

int		on_destroy(t_data *data);
void	draw_sprite(t_data *data);
int		on_keypress(int keysym, t_data *data);
void	render_map(t_data *data);
void	load_map(t_data *data, char *filename);
void	animate_sprite(t_data *data);
int		animate_loop(t_data *data);
void	on_win(t_data *data);
void	on_lose(t_data *data);
void	move_ghosts(t_data *data);
int		animate_move_ghost(t_data *data);
void	validate_path(t_data *data);
t_list	*ft_lst_remove_last(t_list **lst);
void	error(t_data *data, char *str);
int		is_wall(char *line);
int		is_map_rectangular(t_data *data);
void	add_to_queue(t_list **queue, char current_content, int x, int y);
void	free_visited(t_validation *val, int row_len);
void	free_resources(t_data *data);
void	handle_1(t_data *data, int col, int row);
void	handle_0(t_data *data, int col, int row);
void	handle_g(t_data *data, int col, int row);
void	handle_p(t_data *data, int col, int row);
void	handle_e(t_data *data, int col, int row);
void	display_moves(t_data *data);

#endif
