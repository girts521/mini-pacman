/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 10:53:44 by girts             #+#    #+#             */
/*   Updated: 2024/06/16 10:57:25 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "libft.h"

void test_strncmp(const char *s1, const char *s2, size_t n, int expected) {
    int result = ft_strncmp(s1, s2, n);
    printf("strncmp(\"%s\", \"%s\", %zu) = %d, expected = %d\n", s1, s2, n, result, expected);
    if (result == expected) {
        printf("Test passed\n");
    } else {
        printf("Test failed\n");
    }
}

int main() {
    // Test cases
    test_strncmp("apple", "apple", 5, strncmp("apple", "apple", 5));       
    test_strncmp("apple", "apricot", 3, strncmp("apple", "apricot", 3));    
    test_strncmp("apple", "apricot", 5, strncmp("apple", "apricot", 5)); 
    test_strncmp("banana", "ban", 5, strncmp("banana", "ban", 5)); 
    test_strncmp("test", "test", 10, strncmp("test", "test", 10));
    test_strncmp("short", "longer", 5, strncmp("short", "longer", 5)); 
    
    return 0;
}