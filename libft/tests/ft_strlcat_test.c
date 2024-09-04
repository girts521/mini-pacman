/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:06:18 by girts             #+#    #+#             */
/*   Updated: 2024/06/14 10:08:28 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int main()
{
    char dst[20] = "Hello";
    char src[] = " World";
    size_t total_len;

    total_len = ft_strlcat(dst, src, sizeof(dst));
    printf("Resulting dst string: %s\n", dst);
    printf("Total length: %zu\n", total_len);  // Should be the initial length of dst plus the length of src

    return 0;
}