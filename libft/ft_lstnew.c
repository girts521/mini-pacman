/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:54:26 by rchallie          #+#    #+#             */
/*   Updated: 2024/07/03 13:30:30 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(char *content)
{
	t_list *rtn;
	// printf("here inside\n");

	rtn = (t_list *)malloc(sizeof(t_list));
	if (!rtn)
	{
		
		return (rtn = NULL);
	}
		
	
	rtn->next = NULL;
	rtn->content = content;
	rtn->x = 0;
	rtn->y = 0;
	return (rtn);
}
