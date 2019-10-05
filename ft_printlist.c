/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 13:23:05 by mchocho           #+#    #+#             */
/*   Updated: 2019/09/07 12:50:27 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printlist(LinkedList *list, flagobject *flagship)
{
	t_file *current;
	int		i;

	if (!flagship->isvalid || flagship->terminate_ls)
		return ;
	current = list->head;
	i = 0;
	while (current != NULL)
	{
		if (flagship->l_flag || flagship->g_flag)
			ft_longlist(current->filename, flagship);
		else
		{
			if (i != 0)
				ft_putchar('\t');
			ft_putstr(ft_splicepath(current->filename));
		}
		current = current->next;
		i++;
	}
	if (!flagship->l_flag && !flagship->g_flag)
		ft_putchar('\n');
	return ;
}
