/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts521 <girts521@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:28:48 by girts521          #+#    #+#             */
/*   Updated: 2024/06/18 18:28:16 by girts521         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char            *result;
    unsigned int    i;

    if (!s || !f)
        return (NULL);
    i = 0;
    while (s[i])
        i++;
    result = (char *)malloc(sizeof(char) * (i + 1));
    if (!result)
        return (NULL);
    i = 0;
    while (s[i])
    {
        result[i] = f(i, s[i]);
        i++;
    }
    result[i] = '\0';
    return (result);
}
