/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:22:51 by girts             #+#    #+#             */
/*   Updated: 2024/06/17 12:26:29 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"


// Helper test function
void test_ft_strnstr(const char *haystack, const char *needle, size_t len, const char *expected) {
    char *result = strstr(haystack, needle);
    char *expected_result = (char *)expected;
    printf("ft_strnstr(\"%s\", \"%s\", %zu) = %p, expected = %p\n", haystack, needle, len, (void *)result, (void *)expected_result);
    if (result == expected_result) {
        printf("Test passed\n");
    } else {
        printf("Test failed\n");
    }
}

int main() {
    // Test cases
    const char *result;

    result = ft_strnstr("Hello, World!", "World", 13);
    test_ft_strnstr("Hello, World!", "World", 13, result);

    result = ft_strnstr("Hello, World!", "world", 13);
    test_ft_strnstr("Hello, World!", "world", 13, NULL);

    result = ft_strnstr("1234567890", "567", 10);
    test_ft_strnstr("1234567890", "567", 10, result);

    result = ft_strnstr("abcdef", "def", 3);
    test_ft_strnstr("abcdef", "def", 3, NULL);

    result = ft_strnstr("abcdef", "", 6);
    test_ft_strnstr("abcdef", "", 6, "abcdef");

    result = ft_strnstr("abcdef", "cde", 10);
    test_ft_strnstr("abcdef", "cde", 10, result);

    return 0;
}