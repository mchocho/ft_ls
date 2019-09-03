/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addhead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 15:01:03 by mchocho           #+#    #+#             */
/*   Updated: 2019/08/30 17:27:18 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_addhead(LinkedList *list, char* filename, time_t *lm, time_t *acc)
{
	s_file *entry;

	entry = (s_file*)malloc(sizeof(s_file));
	entry->filename = filename;
	entry->lastmodified = ft_constructctimeobj(lm);
	entry->accesstime = ft_constructctimeobj(acc);

	if (list->head == NULL)
	{
		list->tail = entry;
		entry->next = NULL;
	} else
		entry->next = list->head;
	list->head = entry;
}
