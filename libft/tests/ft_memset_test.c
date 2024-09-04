/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarcevs <gkarcevs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:17:22 by gkarcevs          #+#    #+#             */
/*   Updated: 2024/06/13 10:26:33 by gkarcevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int main()
{
    char data[15] = "Hello, World!";

    printf("result before: %s\n", data);
    ft_memset(data, 'a', 2);
    // memset(data, 'a', 2);

    printf("result: %s\n", data);
    return (1);
}