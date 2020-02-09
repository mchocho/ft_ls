/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortbytime.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 14:16:23 by mchocho           #+#    #+#             */
/*   Updated: 2020/02/09 14:17:53 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int		ft_timecmp(t_file *current, t_file *next, int time)
{
	struct stat *current_fs;
	struct stat *next_fs;

	current_fs = &current->file_status;
	next_fs = &next->file_status;
	if (time == 0)
		return (current_fs->st_mtime > next_fs->st_mtime);
	else if (time == 1)
		return (current_fs->st_atime > next_fs->st_atime);
	else
		return (current_fs->st_ctime > next_fs->st_ctime);
}

void			ft_sortbytime(LinkedList *list, int time)
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
			ft_swapnodes(list, &next, &previous);
			continue;
		}
		previous = list->current;
		list->current = next;
	}
	ft_reverselist(list);
	return ;
}
