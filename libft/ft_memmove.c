/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarcevs <gkarcevs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:24:42 by gkarcevs          #+#    #+#             */
/*   Updated: 2024/06/13 11:44:26 by gkarcevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*p_dest;
	unsigned char	*p_src;
	size_t			i;
	unsigned char	temp[1024];

	p_dest = (unsigned char *)dest;
	p_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		temp[i] = p_src[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		p_dest[i] = temp[i];
		i++;
	}
	return (dest);
}
