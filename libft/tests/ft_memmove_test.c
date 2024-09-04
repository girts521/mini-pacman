/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarcevs <gkarcevs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:30:08 by gkarcevs          #+#    #+#             */
/*   Updated: 2024/06/13 11:55:40 by gkarcevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>

int main ()
{
    char dest[15];
    char src[] = "Hello, World!";

    ft_memmove(dest, src, 6);
    // memmove(dest, src, 6);

    printf("result: %s\n", dest);

    return (1);
}