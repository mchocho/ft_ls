/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addhead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 15:01:03 by mchocho           #+#    #+#             */
/*   Updated: 2019/09/07 13:08:46 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_addhead(LinkedList *list, char* filename, time_t lm, time_t acc)
{
	t_file *entry;

	entry = (t_file*)malloc(sizeof(t_file));
	entry->filename = ft_strdup(filename);
	entry->lastmodified = lm;
	entry->accesstime = acc;

	if (list->head == NULL)
	{
		list->tail = entry;
		entry->next = NULL;
	} else
		entry->next = list->head;
	list->head = entry;
}
