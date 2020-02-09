/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapnodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 14:08:28 by mchocho           #+#    #+#             */
/*   Updated: 2020/02/09 14:15:44 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_swapnodes(List *list, t_file **next, t_file **previous)
{
	list->current->next = (*next)->next;
	(*next)->next = list->current;
	if (*previous != NULL)
		(*previous)->next = *next;
	if (ft_structcmp(list->current, list->head))
		list->head = *next;
	if (ft_structcmp(*next, list->tail))
		list->tail = list->current;
	list->current = list->head;
	*previous = NULL;
}
