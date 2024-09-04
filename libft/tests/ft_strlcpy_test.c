/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:27:46 by gkarcevs          #+#    #+#             */
/*   Updated: 2024/06/14 09:56:38 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stddef.h>
#include <string.h>



int main ()
{
	char dst[14];
	char src[14] = "Hello, World!";
	int num;

	printf("size of src: %zu\n", sizeof(src));
	num = ft_strlcpy(dst, src, sizeof(src));
	// num = strlcpy(dst, src, sizeof(src));

	printf("result: %s\n size: %d\n", dst, num);

	return (1);
}