/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverselist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:09:09 by mchocho           #+#    #+#             */
/*   Updated: 2020/02/06 16:10:51 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			ft_reverselist(List *list)
{
	t_file		*current;
	t_file		*next;
	t_file		*prev;

	current = list->head;
	next = NULL;
	prev = NULL;
	list->tail = current;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	list->head = prev;
	return ;
}
