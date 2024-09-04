/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarcevs <gkarcevs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:05:22 by gkarcevs          #+#    #+#             */
/*   Updated: 2024/06/18 10:44:50 by gkarcevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_pow( int base, int power)
{
	int	i;
	int	initial_base;

	initial_base = base;
	i = power;
	if (power == 0)
		return (1);
	while (i > 1)
	{
		base = base * initial_base;
		i--;
	}
	return (base);
}

int	ft_atoi(char *str)
{
	int		i;
	int		minus_count;
	char	nums[1024];
	int		nums_i;
	int		result;

	result = 0;
	nums_i = 0;
	i = 0;
	minus_count = 0;
	while (str[i] == '-' || str[i] == '+' || str[i] == ' ')
	{
		if (str[i++] == '-')
			minus_count++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
		nums[nums_i++] = str[i++];
	nums[nums_i] = '\0';
	i = ft_strlen(nums) -1 ;
	nums_i = 0;
	while (i >= 0)
		result += (nums[nums_i++] - 48) * (ft_pow(10, i--));
	if (minus_count % 2 == 1)
		return (result - (result * 2));
	return (result);
}
