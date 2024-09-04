/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts521 <girts521@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:43:54 by girts521          #+#    #+#             */
/*   Updated: 2024/06/18 16:47:02 by girts521         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int is_in_set(char c, const char *set)
{
    size_t i;

    i = 0;
    while (set[i])
    {
        if (c == set[i])
            return (1);
        i++;
    }
    return (0);
}

char *ft_strtrim(char const *s1, char const *set)
{
    char *trimmed_str;
    size_t start;
    size_t end;
    size_t len;
    size_t i;

    trimmed_str = NULL;
    start = 0;
    end = 0;
    len = 0;
    i = 0;

    if (s1 == NULL || set == NULL)
        return (NULL);

    while (s1[start] && is_in_set(s1[start], set))
        start++;

    end = ft_strlen((char *)s1);
    while (end > start && is_in_set(s1[end - 1], set))
        end--;

    len = end - start;
    trimmed_str = (char *)malloc((len + 1) * sizeof(char));
    if (trimmed_str == NULL)
        return (NULL);

    while (i < len)
    {
        trimmed_str[i] = s1[start + i];
        i++;
    }

    trimmed_str[len] = '\0';
    return (trimmed_str);
}