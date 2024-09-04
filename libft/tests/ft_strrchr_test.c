/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:23:49 by girts             #+#    #+#             */
/*   Updated: 2024/06/14 17:24:08 by girts            ###   ########.fr       */
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

	printf("%s\n", ft_strrchr(str, c));
	printf("%s\n", strrchr(str, c));

	return 0;
}