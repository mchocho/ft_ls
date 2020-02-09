/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addtail.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 11:09:39 by mchocho           #+#    #+#             */
/*   Updated: 2019/09/05 14:05:59 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_addtail(List *list, char *filename, struct stat *fstat)
{
	t_file *child;

	child = (t_file*)malloc(sizeof(t_file));
	child->filename = ft_strdup(filename);
	child->file_status = *fstat;
	child->next = NULL;
	if (list->head == NULL)
		list->head = child;
	else
		list->tail->next = child;
	list->tail = child;
}
