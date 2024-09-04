/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarcevs <gkarcevs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:44:58 by girts             #+#    #+#             */
/*   Updated: 2024/06/13 09:52:25 by gkarcevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stddef.h>

void print_memory(const void *s, size_t n)
{
    const unsigned char *p = (const unsigned char *)s;
    for (size_t i = 0; i < n; ++i) {
        printf("%02x ", p[i]);
    }
    printf("\n");
}

void print_string(const char *s, size_t n)
{
    for (size_t i = 0; i < n; ++i) {
        if (s[i] == '\0')
            printf("\\0");  // Print a visual representation of null character
        else
            putchar(s[i]);
    }
    printf("\n");
}

int main()
{
    char data[15] = "Hello, World!";
    
    printf("Before ft_bzero:\n");
    // Print as characters, handling null characters explicitly
    printf("Data as string: \"");
    print_string(data, sizeof(data));
    printf("\"\n");
    // Print as hex bytes
    printf("Data as hex: ");
    print_memory(data, sizeof(data));
    
    // Set first 5 bytes to zero
    ft_bzero(data, 5);
    
    printf("\nAfter ft_bzero:\n");
    // Print as characters, handling null characters explicitly
    printf("Data as string: \"");
    print_string(data, sizeof(data));
    printf("\"\n");
    // Print as hex bytes
    printf("Data as hex: ");
    print_memory(data, sizeof(data));

    return 0;
}