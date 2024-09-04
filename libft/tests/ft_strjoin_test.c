/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts521 <girts521@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:37:14 by girts521          #+#    #+#             */
/*   Updated: 2024/06/18 16:42:17 by girts521         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int main ()
{
    char str[] = "Hello,";
    char str2[] = " world!";
    char *result;
    result = ft_strjoin(str, str2);
    printf("result: %s\n", result);
    return (1);
}