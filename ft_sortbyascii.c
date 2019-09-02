/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortbyascii.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 15:35:29 by mchocho           #+#    #+#             */
/*   Updated: 2019/09/02 12:05:38 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    ft_sortbytime(LinkedList *list)
{
        t_file *current;
        t_file *next;

        current = list->head;
        while (current != NULL)
        {
                next = current->next;
                if (ft_strcmp(current->filename, next->filename))
                {
                        current->next = next->next;
                        next->next = current;
                        if (ft_structcmp(next, list->head))
                                list->head = current;
                        if (ft_structcmp(current, list->tail))
                                list->tail = next;
                        current = list->head;
                        continue;
                }
                current = next;
        }
        return ;
}
