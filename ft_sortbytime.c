/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortbytime.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 14:16:23 by mchocho           #+#    #+#             */
/*   Updated: 2019/08/30 14:23:50 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_sortbytime(LinkedList *list)
{
	t_file *current;
	t_file *next;

	current = list->head;
	while (current != NULL)
	{
		next = current->next;
		if (current->lastmodified->epoch < next->lastmodified->epoch)
		{
			current->next = next->next;
			next->next = current;
			if (ft_structcmp(next, list->head))
				list->head = current;
			if (ft_structcmp(current, list->tail))
				list->tail = next;
			current = list->head;
			continue;
		}
		current = next;
	}
	return ;
}
