/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:17:09 by girts             #+#    #+#             */
/*   Updated: 2024/07/03 17:28:29 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


// Initialization: Create a queue or stack and push the starting position onto it.
// Exploration:
// Pop the top element (current position) from the stack/queue.
// Check all adjacent cells (up, down, left, right).
// If an adjacent cell is unvisited and not a wall, mark it as visited and push it onto the stack/queue.
// Goal Check: As you explore, check if you have reached all collectibles and the exit.
// Completion: If the queue/stack is empty and not all goals are reached, the map is invalid.


// t_list	*ft_lst_remove_last(t_list *lst)
// {
// 	t_list *last;
// 	t_list	*current_node;
// 	t_list	*previous_node;

// 	 if (!lst) // Check if list is empty
//         return NULL;

// 	last = lst;
// 	current_node = lst;
// 	previous_node = NULL;

// 	while(current_node)
// 	{
// 		if(current_node->next == NULL)
// 		{
// 			last = current_node;
// 			if (previous_node)
//                 previous_node->next = NULL;
// 			else
//                 lst = NULL;
// 			break ;
// 		}
// 		previous_node = current_node;
// 		current_node = current_node->next;
// 	}
// 	return (last);
// }

void print_visited(char **visited, int rowlen, int collen) {
    int row = 0;
    int col;
    while (row < rowlen) {
        col = 0;
        while (col < collen) {
            if (visited[row][col] == '\0') // Check for null character and print '0'
                printf("0");
            else
                printf("%c", visited[row][col]);
            col++;
        }
        printf("\n");
        row++;
    }
}

t_list *ft_lst_remove_last(t_list **lst) {
    t_list *current = *lst;
    t_list *prev = NULL;

    if (!current)
        return (NULL);
    if (!current->next) {
        *lst = NULL;
        return (current);
    }
    while (current->next) {
        prev = current;
        current = current->next;
    }
    if (prev)
        prev->next = NULL;
    return (current);
}

static int is_wall(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] != '1')
            return (0);
        i++;
    }
    return (1);
}

static int is_map_rectangular(t_data *data) {
    int first_row_length = ft_strlen(data->map[0]);

    for (int i = 1; i < data->row_len; i++) {
        if (ft_strlen(data->map[i]) != first_row_length) {
            return 0;
        }
    }

    return 1;
}

int validate_path(t_data *data)
{
    t_list *queue; // add at start, take from back
    // int		lstsize;
    int x;
    int y;
    t_list	*current_node;
    int to_collect;
    int exit;
    t_list	*right_node;
    t_list	*left_node;
    t_list	*up_node;
    t_list	*down_node;
    char current_content;
    char **visited;


	if(!is_map_rectangular(data))
	{
		fprintf(stderr,"Error\n");
		printf("Invalid map, not all lines are the same length. Map must be rectangular\n");
		on_destroy(data);
		return (0);
	}

	if(data->map[0])
	{
		printf("at validate map 0: %s\n", data->map[0]);
		if(!is_wall(data->map[0]))
		{
			fprintf(stderr,"Error\n");
			printf("Invalid map, first line must be a wall\n");
			on_destroy(data);
			return (0);
		}
	}

	if(data->map[data->row_len - 1])
	{
		printf("at validate map last: %s\n", data->map[data->row_len - 1]);
		if(!is_wall(data->map[data->row_len - 1]))
		{
			fprintf(stderr,"Error\n");
			printf("Invalid map, last line must be a wall\n");
			on_destroy(data);
			return (0);
		}
	}

	//first and last c of each line must we 1
	for (int i = 0; i < data->row_len; i++)
	{
		if (data->map[i][0] != '1' || data->map[i][data->col_len - 1] != '1')
		{
			fprintf(stderr,"Error\n");
			printf("Invalid map, first and last c of each line must be 1\n");
			on_destroy(data);
			return (0);
		}
	}

    visited = malloc(data->row_len * sizeof(char *));
    for (int i = 0; i < data->row_len; i++) {
        visited[i] = calloc(data->col_len, sizeof(char));
        ft_bzero(visited[i], data->col_len);
    }
    x = data->x / 16;
    y = data->y / 16;
    to_collect = data->collectable_count;
    exit = 1;

	
    // y - 1 = up
    // y + 1 = down
    // x + 1 = right
    // x - 1 = left

	// printf("here x: %d and y: %d\n", x, y);

    current_content = data->map[y][x];
    queue = ft_lstnew(&current_content);
    queue->x = x;
    queue->y = y;
    visited[y][x] = '1';
    while (ft_lstsize(queue) > 0)
    {
        current_node = ft_lst_remove_last(&queue);
        x = current_node->x;
        y = current_node->y;
        if (y > 0 && data->map[y - 1][x] != '1' && visited[y - 1][x] != '1' && visited[y - 1][x] != 'C') // Corrected boundary check
        {
            // printf("here up \n");
            current_content = data->map[y - 1][x];
			// printf("current content: %c\n", (current_content));
			if((current_content) == 'C' && to_collect > 0)
			{
				to_collect--;
				visited[y - 1][x] = 'C';
				printf("Collectable found at (%d, %d). Remaining: %d\n", x, y - 1, to_collect);
			}
			else if ((current_content) == 'E' && exit > 0)
			{
				printf("here exit \n");
				exit--;
				visited[y - 1][x] = '1';
			}
			else
			{
				visited[y - 1][x] = '1';
			}
            up_node = ft_lstnew(&current_content);
            up_node->x = x;
            up_node->y = y - 1;
            // printf("up node: %c\n", *(char *)(up_node->content));
            ft_lstadd_front(&queue, up_node);
            
            // printf("up node: %c\n", *(char *)(up_node->content));
        }
        if (y < data->row_len - 1 && data->map[y + 1][x] != '1' && visited[y + 1][x] != '1' && visited[y + 1][x] != 'C') // Corrected boundary check
        {
            // printf("here down \n");
            current_content = data->map[y + 1][x];
			printf("current content: %c\n", (current_content));
			if((current_content) == 'C' && to_collect > 0)
			{
				to_collect--;
				visited[y + 1][x] = 'C';
				printf("Collectable found at (%d, %d). Remaining: %d\n", x, y + 1, to_collect);
			}
			else if ((current_content) == 'E' && exit > 0)
			{
				printf("here exit \n");
				visited[y + 1][x] = '1';
				exit--;
			}
			else
			{
				visited[y + 1][x] = '1';

			}
            down_node = ft_lstnew(&current_content);
            down_node->x = x;
            down_node->y = y + 1;
            ft_lstadd_front(&queue, down_node);
        }
        if(x > 0 && data->map[y][x - 1] != '1' && visited[y][x - 1] != '1' && visited[y][x - 1] != 'C') // Corrected boundary check
        {
            // printf("here left \n");
            current_content = data->map[y][x - 1];
			printf("current content: %c\n", (current_content));
			if((current_content) == 'C' && to_collect > 0)
			{
				to_collect--;
				visited[y][x - 1] = 'C';
				printf("Collectable found at (%d, %d). Remaining: %d\n", x - 1, y, to_collect);
			}
			else if ((current_content) == 'E' && exit > 0)
			{
				printf("here exit \n");
				exit--;
				// visited[y][x - 1] = 'E';
				visited[y][x - 1] = '1';
				printf("Exit found at (%d, %d). Remaining: %d\n", x - 1, y, exit);
			}
			else
			{
				visited[y][x - 1] = '1';
			}
            left_node = ft_lstnew(&current_content);
            left_node->x = x - 1;
            left_node->y = y;
            ft_lstadd_front(&queue, left_node);
        }
        if(x < data->col_len - 1 && data->map[y][x + 1] != '1' && visited[y][x + 1] != '1'  && visited[y][x + 1] != 'C') // Corrected boundary check
        {
            // printf("here right \n");
            current_content = data->map[y][x + 1];
			printf("current content: %c\n", (current_content));
			if((current_content) == 'C' && to_collect > 0)
			{
				to_collect--;
				visited[y][x + 1] = 'C';
				printf("Collectable found at (%d, %d). Remaining: %d\n", x + 1, y, to_collect);
			}
			else if ((current_content) == 'E' && exit > 0)
			{
				exit--;
				printf("Exit found at (%d, %d)\n", x + 1, y);
				visited[y][x + 1] = '1';
			}
			else
			{
				visited[y][x + 1] = '1';
			}
            right_node = ft_lstnew(&current_content);
            right_node->x = x + 1;
            right_node->y = y;
            
            ft_lstadd_front(&queue, right_node);
        }
    }
    print_visited(visited, data->row_len, data->col_len);

    if (to_collect == 0 && exit == 0)
    {
        printf("Map is valid\n");
        return (1);
    }
    else
    {
		fprintf(stderr,"Error\n");
        printf("Map is not valid!\nNot all collectibles and exits can be reached.\n");
		printf("Missing %d collectibles. Locations:\n", to_collect);
    	for (int i = 0; i < data->row_len; i++)
    	{
        	for (int j = 0; j < data->col_len; j++)
        	{
            	if (data->map[i][j] == 'C' && visited[i][j] != 'C')
            	{
                	printf("Missed collectable at (%d, %d)\n", j, i);
            	}
        	}
    	}
		on_destroy(data);
        return (0);
    }

}