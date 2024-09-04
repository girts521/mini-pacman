/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts521 <girts521@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 08:42:50 by girts521          #+#    #+#             */
/*   Updated: 2024/06/20 08:47:23 by girts521         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int main()
{
    char content[] = "Hello, World!";
    t_list *list;

    list = ft_lstnew(content);
    printf("the content is: %s\n", (char *)list->content);
    return (1);

}