/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortbyascii.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 15:35:29 by mchocho           #+#    #+#             */
/*   Updated: 2019/09/03 12:55:29 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		ft_sortbyascii(LinkedList *list)
{
        t_file *current;
        t_file *next;
	t_file *previous;

        current = list->head;
	previous = NULL;
        while (current != NULL && current->next != NULL)
        {
                next = current->next;
                if (ft_strcmpi(current->filename, next->filename))
                {
                        current->next = next->next;
                        next->next = current;
			if (previous != NULL)
				previous->next = next;
                        if (ft_structcmp(next, list->head))
                                list->head = current;
                        if (ft_structcmp(current, list->tail))
                                list->tail = next;
			previous = NULL;
                        current = list->head;
                        continue;
                }
		previous = current;
                current = next;
        }
        return ;
}
