/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts521 <girts521@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:10:23 by girts521          #+#    #+#             */
/*   Updated: 2024/06/18 17:16:12 by girts521         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include  <stdio.h>

int main()
{
    char str[] = "Hello, world !";
    char	**result;
    result = ft_split(str, ' ');
    printf("result: %s\n", result[0]);
    printf("result: %s\n", result[1]);
    printf("result: %s\n", result[2]);

    return (1);

}