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

#include "../includes/ft_ls.h"

static int	ft_nsecondscmp(t_file *current, t_file *next)
{
	return (current->file_status->st_mtim.tv_nsec < next->file_status->st_mtim.tv_nsec);
}

static int	ft_timecmp(t_file *current, t_file *next)
{
	//if (current->file_status->st_atime == next->file_status->st_atime)
	if (current->file_status->st_mtime == next->file_status->st_mtime)
		return (ft_nsecondscmp(current, next));
	return (current->file_status->st_mtime > next->file_status->st_mtime);
}

void		ft_sortbytime(LinkedList *list)
{
	t_file *next;
	t_file *previous;

	if (list == NULL)
		return ;
	list->current = list->head;
	previous = NULL;
	while (list->current != NULL && list->current->next != NULL)
	{
		next = list->current->next;
		if (ft_timecmp(list->current, next))
		{
			list->current->next = next->next;	//Current is taking next's position
			next->next = list->current;		//Next is pointing to (in front of) current
			if (previous != NULL)
				previous->next = next;	//Current's previous node (if it is a node) is now in front of next
			if (ft_structcmp(next, list->head))
				list->head = list->current;
			if (ft_structcmp(list->current, list->tail))
				list->tail = next;
			list->current = list->head;
			previous = NULL;
			continue;
		} 
		previous = list->current;
		list->current = next;
	}
	return ;
}
