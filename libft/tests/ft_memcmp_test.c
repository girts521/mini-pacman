/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 11:14:45 by girts             #+#    #+#             */
/*   Updated: 2024/06/16 11:21:33 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include "libft.h"
#include <string.h>

void test_ft_memcmp(const void *s1, const void *s2, size_t n, int expected) {
    int result = ft_memcmp(s1, s2, n);
    printf("ft_memcmp(\"%s\", \"%s\", %zu) = %d, expected = %d\n", (const char *)s1, (const char *)s2, n, result, expected);
    if (result == expected) {
        printf("Test passed\n");
    } else {
        printf("Test failed\n");
    }
}

int main() {
    const char str1[] = "abcdef";
    const char str2[] = "abcxyz";
    const char str3[] = "abcdef";
    
    // Test cases
    test_ft_memcmp(str1, str2, 3, memcmp(str1, str2, 3));
    test_ft_memcmp(str1, str2, 4, memcmp(str1, str2, 4));
    test_ft_memcmp(str1, str3, 6, memcmp(str1, str3, 6)); 
    test_ft_memcmp(str1, str2, 6, memcmp(str1, str2, 6));
    test_ft_memcmp("12345", "1234", 5, memcmp("12345", "1234", 5)); 

    return 0;
}