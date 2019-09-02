/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addtail.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 11:09:39 by mchocho           #+#    #+#             */
/*   Updated: 2019/09/02 11:16:12 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_addtail(LinkedList *list, char *filename, time_t lm, time_t acc)
{
	t_file *entry;
	
	entry = (t_file*)malloc(sizeof(t_file));
	entry->filename = filename;
	entry->lastmodified = ft_constructctimeobj(lm);
	entry->accesstime = ft_constructctimeobj(acc);
	entry->next = NULL;
	if (list->head == NULL)
		list->head = entry;
	else
		list->tail->next = entry;
	list->tail = entry;
}
