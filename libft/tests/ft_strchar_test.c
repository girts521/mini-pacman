/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchar_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:10:40 by girts             #+#    #+#             */
/*   Updated: 2024/06/14 17:16:42 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"
#include <stddef.h>

int main()
{
	char str[] = "Hello, World!";
	char c = 'l';

	// printf("%s\n", ft_strchr(str, c));
	printf("%s\n", strchr(str, c));

	return 0;
}