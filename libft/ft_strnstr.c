/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts521 <girts521@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:19:20 by girts             #+#    #+#             */
/*   Updated: 2024/06/18 17:10:10 by girts521         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	i;

	if (*needle == '\0')
		return ((char *)haystack);
	needle_len = 0;
	while (needle[needle_len] != '\0')
		needle_len++;
	if (len == 0 || needle_len == 0)
		return (NULL);
	i = 0;
	while (i + needle_len <= len && haystack[i] != '\0')
	{
		if (haystack[i] == needle[0])
		{
			if (haystack[i + needle_len - 1] == needle[needle_len - 1])
			{
				if (ft_strncmp(&haystack[i], needle, needle_len) == 0)
					return ((char *)&haystack[i]);
			}
		}
		i++;
	}
	return (NULL);
}
