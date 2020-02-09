/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortbyascii.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 15:35:29 by mchocho           #+#    #+#             */
/*   Updated: 2020/02/08 13:05:16 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			ft_sortbyascii(LinkedList *list)
{
	t_file *current;
	t_file *next;
	t_file *previous;

	current = list->head;
	previous = NULL;
	while (current != NULL && current->next != NULL)
	{
		next = current->next;
		if (ft_tolower(current->filename[0]) > ft_tolower(next->filename[0]))
		{
			current->next = next->next;
			next->next = current;
			if (previous != NULL)
				previous->next = next;
			if (ft_structcmp(next, list->head))
				list->head = current;
			if (ft_structcmp(current, list->tail))
				list->tail = next;
			previous = NULL;
			current = list->head;
			continue;
		}
		previous = current;
		current = next;
	}
}
