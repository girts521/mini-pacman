/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarcevs <gkarcevs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:32:41 by gkarcevs          #+#    #+#             */
/*   Updated: 2024/06/18 15:25:25 by gkarcevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Test 1: Regular allocation
    size_t nmemb = 10;
    size_t size = sizeof(int);
    int *arr = (int *)ft_calloc(nmemb, size);
    if (arr == NULL) {
        printf("Test 1 failed: allocation returned NULL\n");
    } else {
        int success = 1;
        for (size_t i = 0; i < nmemb; i++) {
            if (arr[i] != 0) {
                success = 0;
                break;
            }
        }
        printf("Test 1 %s: regular allocation and zero-initialization\n", success ? "passed" : "failed");
        free(arr);
    }

    // Test 2: Allocation of zero elements
    nmemb = 0;
    size = sizeof(int);
    arr = (int *)ft_calloc(nmemb, size);
    if (arr == NULL) {
        printf("Test 2 passed: allocation of zero elements returned NULL\n");
    } else {
        printf("Test 2 failed: allocation of zero elements did not return NULL\n");
        free(arr);
    }

    // Test 3: Large allocation to check overflow
    nmemb = (size_t)-1;
    size = sizeof(int);
    arr = (int *)ft_calloc(nmemb, size);
    if (arr == NULL) {
        printf("Test 3 passed: detected integer overflow\n");
    } else {
        printf("Test 3 failed: did not detect integer overflow\n");
        free(arr);
    }

    return 0;
}