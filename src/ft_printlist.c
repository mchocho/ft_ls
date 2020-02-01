/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 13:23:05 by mchocho           #+#    #+#             */
/*   Updated: 2019/12/03 14:09:47 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_printlist(LinkedList *list, flagobject *flagship)
{
	//t_file *current;
	int	i;

	if (!flagship->isvalid || flagship->terminate_ls)
		return ;
	list->current = list->head;
	i = 0;
	while (list->current != NULL)
	{
		if (flagship->l_flag || flagship->g_flag)
			ft_longlist(list->current, flagship);
		else
		{
			if (i != 0)
				ft_putchar('\n');
			ft_putstr(ft_splicepath(list->current->filename));
		}
		list->current = list->current->next;
		i++;
	}
	if (!flagship->l_flag && !flagship->g_flag)
		ft_putchar('\n');
	return ;
}
