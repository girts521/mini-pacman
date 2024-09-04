/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarcevs <gkarcevs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:46:27 by gkarcevs          #+#    #+#             */
/*   Updated: 2024/06/18 13:47:26 by gkarcevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    const char *original = "Hello, World!";
    char *duplicate;

    duplicate = ft_strdup(original);

    if (duplicate == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Original: %s\n", original);
    printf("Duplicate: %s\n", duplicate);

    free(duplicate); 
    return 0;
}
