/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts521 <girts521@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:48:30 by girts521          #+#    #+#             */
/*   Updated: 2024/06/18 16:52:37 by girts521         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int main()
{
    char set[] = "+-. ";
    char str[] = " --+hello!+- ";
    char *result;

    result = ft_strtrim(str, set);
    printf("result: %s\n", result);

    return (1);

}