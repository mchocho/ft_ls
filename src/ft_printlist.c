/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 13:23:05 by mchocho           #+#    #+#             */
/*   Updated: 2020/02/09 16:09:46 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int				ft_isdir(char *path)
{
	struct stat		fstat;

	if (stat(path, &fstat) < 0)
		return (0);
	return (ft_strichr("d", ft_filetype(&fstat)) > -1);
}

void					ft_printlist(List *list, flagobject *flagship)
{
	int					i;

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
			if (ft_isdir(list->current->filename))
				ft_putstr(MAGENTA);
			ft_putstr(ft_splicepath(list->current->filename));
			ft_putstr(NO_COL);
		}
		list->current = list->current->next;
		i++;
	}
	list->current = list->head;
	if (!flagship->l_flag && !flagship->g_flag)
		ft_putchar('\n');
}
