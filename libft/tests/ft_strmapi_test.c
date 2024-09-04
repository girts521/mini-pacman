/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts521 <girts521@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:21:39 by girts521          #+#    #+#             */
/*   Updated: 2024/06/18 18:27:15 by girts521         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char to_upper(unsigned int index, char c)
{
    index = index +1;
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);
}

int main()
{
    char str[] = "Hello, World!";
    char *result;

    result = ft_strmapi(str, to_upper);

    printf("result: %s\n", result);

    return (1);

}