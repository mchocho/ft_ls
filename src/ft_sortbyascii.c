/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortbyascii.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 15:35:29 by mchocho           #+#    #+#             */
/*   Updated: 2020/02/09 14:43:33 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int		ft_filecmp(t_file *current, t_file *next)
{
	return (ft_strcmp(current->filename, next->filename) > 0);
}

void			ft_sortbyascii(List *list)
{
	t_file *next;
	t_file *previous;

	list->current = list->head;
	previous = NULL;
	while (list->current != NULL && list->current->next != NULL)
	{
		next = list->current->next;
		if (ft_filecmp(list->current, next))
		{
			ft_swapnodes(list, &next, &previous);
			continue;
		}
		previous = list->current;
		list->current = next;
	}
}
