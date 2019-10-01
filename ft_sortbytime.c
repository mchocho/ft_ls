/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortbytime.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 14:16:23 by mchocho           #+#    #+#             */
/*   Updated: 2019/09/17 18:10:50 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


static int	ft_timecmp(t_file *current, t_file *next)
{
	if (current->lastmodified == next->lastmodified)
		return (ft_nsecondscmp(current->filename, next->filename, 1));
	return (current->lastmodified < next->lastmodified);
}

void		ft_sortbytime(LinkedList *list)
{
	t_file *current;
	t_file *next;
	t_file *previous;

	current = list->head;
	previous = NULL;
	while (current != NULL && current->next != NULL)
	{
		next = current->next;
		if (ft_timecmp(current, next))
		{
			current->next = next->next;	//Current is taking next's position
			next->next = current;		//Next is pointing to (in front of) current
			if (previous != NULL)
				previous->next = next;	//Current's previous node (if it is a node) is now in front of next
			if (ft_structcmp(next, list->head))
				list->head = current;
			if (ft_structcmp(current, list->tail))
				list->tail = next;
			current = list->head;
			previous = NULL;
			continue;
		} 
		previous = current;
		current = next;
	}
	return ;
}
