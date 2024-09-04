/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts521 <girts521@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:53:44 by girts521          #+#    #+#             */
/*   Updated: 2024/06/18 19:02:12 by girts521         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int main()
{
    int fd = open("./test.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    ft_putstr_fd("Hello, world", fd);
    return (1);
}