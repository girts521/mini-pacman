/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:19:08 by girts521          #+#    #+#             */
/*   Updated: 2024/07/28 20:29:45 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int  num_len(int n)
{
    int len;

    len = 0;
    if (n <= 0)
        len++;
    while (n != 0)
    {
        len++;
        n /= 10;
    }
    return (len);
}

char    *ft_itoa(int n)
{
    char    *str;
    int     len;
    long    nbr;

    len = num_len(n);
    str = (char *)malloc(sizeof(char) * (len + 1));
    if (!str)
        return (NULL);
    str[len] = '\0';
    ft_bzero(str, len + 1);
    nbr = n;
    if (nbr < 0)
    {
        str[0] = '-';
        nbr = -nbr;
    }
    while (len > 0 && str[len - 1] != '-')
    {
        str[--len] = (nbr % 10) + '0';
        nbr /= 10;
    }
    return (str);
}
