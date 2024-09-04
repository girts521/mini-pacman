/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:19:59 by girts             #+#    #+#             */
/*   Updated: 2024/07/19 21:54:55 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"

typedef struct gnl_s
{
	char	*buffer;
	char	*line;
	int		bytes_read;
	size_t	line_len;
	size_t	buffer_len;
}	t_gnl;

char	*get_next_line(int fd);
char	*ft_realloc(char *ptr, size_t size);
int		handle_buffer(t_gnl *data, char	**newline_pos);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

#endif
