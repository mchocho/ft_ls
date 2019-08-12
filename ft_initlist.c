/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 12:59:09 by mchocho           #+#    #+#             */
/*   Updated: 2019/08/12 12:59:16 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_initlist(LinkedList *list)
{
	list->head = NULL;
	list->tail = NULL;
	list->current = NULL;
}
