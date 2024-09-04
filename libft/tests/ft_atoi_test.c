/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarcevs <gkarcevs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:08:27 by gkarcevs          #+#    #+#             */
/*   Updated: 2024/06/18 10:42:37 by gkarcevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num;

	num = 0;

	num = ft_atoi("13");
	printf("num is: %d and expected: %d\n",num, atoi("13"));
	if (num == atoi("13"))
		printf("Test passed\n");
	else
		printf("Test not passed\n");

	num = ft_atoi("-13");
	printf("num is: %d and expected: %d\n",num, atoi("-13"));
	if (num == atoi("-13"))
		printf("Test passed\n");
	else
		printf("Test not passed\n");

	num = ft_atoi("-25678");
	printf("num is: %d and expected: %d\n",num, atoi("-25678"));
	if (num == atoi("-25678"))
		printf("Test passed\n");
	else
		printf("Test not passed\n");

	num = ft_atoi("2147483647");
	printf("num is: %d and expected: %d\n",num, atoi("2147483647"));
	if (num == atoi("2147483647"))
		printf("Test passed\n");
	else
		printf("Test not passed\n");

	num = ft_atoi("--25678");
	printf("num is: %d and expected: %d\n",num, atoi("--25678"));
	if (num == atoi("--25678"))
		printf("Test passed\n");
	else
		printf("Test not passed\n");

	num = ft_atoi("-+++--25678");
	printf("num is: %d and expected: %d\n",num, atoi("-+++--25678"));
	if (num == atoi("-+++--25678"))
		printf("Test passed\n");
	else
		printf("Test not passed\n");
}