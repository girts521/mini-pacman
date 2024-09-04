/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarcevs <gkarcevs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:27:14 by gkarcevs          #+#    #+#             */
/*   Updated: 2024/06/13 10:29:10 by gkarcevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int main()
{
    char str[] = "Hello, world";
    int num;

    num = ft_strlen(str);
    printf("result: %d\n", num);

    return (1);
}
