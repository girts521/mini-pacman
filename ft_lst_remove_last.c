/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_remove_last.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:44:54 by girts             #+#    #+#             */
/*   Updated: 2024/07/03 21:45:58 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list	*ft_lst_remove_last(t_list **lst)
{
	t_list	*current;
	t_list	*prev;

	current = *lst;
	prev = NULL;
	if (!current)
		return (NULL);
	if (!current->next)
	{
		*lst = NULL;
		return (current);
	}
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	if (prev)
		prev->next = NULL;
	return (current);
}
