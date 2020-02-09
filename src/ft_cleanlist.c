/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:15:03 by mchocho           #+#    #+#             */
/*   Updated: 2020/02/06 16:15:07 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_cleanlist(LinkedList **list)
{
	t_file *current;
	t_file *next;

	current = (*list)->head;
	while (current != NULL)
	{
		next = current->next;
		ft_strcleandel(&current->filename);
		current->next = NULL;
		free(current);
		current = next;
	}
	(*list)->head = NULL;
	(*list)->tail = NULL;
	(*list)->current = NULL;
	free(*list);
}
