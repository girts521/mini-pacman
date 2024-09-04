/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarcevs <gkarcevs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:39:55 by gkarcevs          #+#    #+#             */
/*   Updated: 2024/06/18 15:56:09 by gkarcevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int main ()
{
	char *str = "Hello, world!";
	char *substr;

	substr = ft_substr(str, 0, 5);
	printf("result of ft_substr(Hello, world!, 0, 5): %s\n", substr);

	substr = ft_substr(str, 7, 5);
	printf("result of ft_substr(Hello, world!, 7, 5): %s\n", substr);

	substr = ft_substr(str, 7, 100);
	printf("result of ft_substr(Hello, world!, 7, 100): %s\n", substr);

	substr = ft_substr(str, 14, 5);
	printf("result of ft_substr(Hello, world!, 14, 5): %s\n", substr);
	return (1);

}