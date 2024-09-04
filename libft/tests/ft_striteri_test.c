/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts521 <girts521@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:37:51 by girts521          #+#    #+#             */
/*   Updated: 2024/06/18 18:46:54 by girts521         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void to_upper(unsigned int index, char *c)
{
    index = index +1;
    if (*c >= 'a' && *c <= 'z')
        *c = *c - 32;
}

int main()
{
    char str[] = "Hello, World!";
    ft_striteri(str, to_upper);

    printf("result: %s\n", str);
    return (1);
}