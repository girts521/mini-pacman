/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 11:03:23 by girts             #+#    #+#             */
/*   Updated: 2024/06/16 11:05:23 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include "libft.h"
#include <string.h>

void test_ft_memchr(const void *s, int c, size_t n, const void *expected) {
    const void *result = ft_memchr(s, c, n);
    printf("ft_memchr(\"%s\", '%c', %zu) = %p, expected = %p\n", (const char *)s, c, n, result, expected);
    if (result == expected) {
        printf("Test passed\n");
    } else {
        printf("Test failed\n");
    }
}

int main() {
    const char str[] = "Hello, World!";
    
    // Test cases
    test_ft_memchr(str, 'W', 13, memchr( str, 'W', 13 ));
    test_ft_memchr(str, 'o', 13, memchr( str, 'o', 13 ));
    test_ft_memchr(str, 'z', 13, memchr( str, 'z', 13 ));
    test_ft_memchr(str, 'l', 13, memchr( str, 'l', 13 )); 
    test_ft_memchr(str, 'H', 1, memchr( str, 'H', 1 ));
    test_ft_memchr(str, '\0', 14, memchr( str, '\0', 14 )); 
    
    return 0;
}
