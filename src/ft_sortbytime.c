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

static int	ft_nsecondscmp(struct stat *current, struct stat *next, int t)
{
	if (t == 0)
		return (current->st_mtim.tv_nsec > next->st_mtim.tv_nsec);
	else if (t == 1)
		return (current->st_atim.tv_nsec > next->st_atim.tv_nsec);
	else
		return (current->st_ctim.tv_nsec > next->st_ctim.tv_nsec);
}

static int	ft_timecmp(t_file *current, t_file *next, int time)
{
	struct stat *current_fs;
	struct stat *next_fs;
	
	current_fs = &current->file_status;
	next_fs = &next->file_status;
	
	if (time == 0)
	{
		if (current_fs->st_mtime == next_fs->st_mtime)
			return (ft_nsecondscmp(current_fs, next_fs, 0));
		return (current_fs->st_mtime > next_fs->st_mtime);
	}
	else if (time == 1)
	{
		if (current_fs->st_atime == next_fs->st_atime)
			return (ft_nsecondscmp(current_fs, next_fs, 1));
		return (current_fs->st_atime > next_fs->st_atime);
	}
	else
	{
		if (current_fs->st_ctime == next_fs->st_ctime)
			return (ft_nsecondscmp(current_fs, next_fs, 'c'));
		return (current_fs->st_ctime > next_fs->st_ctime);
	}
}

void		ft_sortbytime(LinkedList *list, int time)
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
		if (ft_timecmp(list->current, next, time))
		{
			list->current->next = next->next;
			next->next = list->current;
			if (previous != NULL)
				previous->next = next;
			if (ft_structcmp(list->current, list->head))
				list->head = next;
			if (ft_structcmp(next, list->tail))
				list->tail = list->current;
			list->current = list->head;
			previous = NULL;
			continue;
		} 
		previous = list->current;
		list->current = next;
	}
	ft_reverselist(list);
	return ;
}
