/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 13:09:18 by mchocho           #+#    #+#             */
/*   Updated: 2020/02/09 16:10:22 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_sortlist(List *list, flagobject *flagship)
{
	if (!flagship->isvalid || flagship->terminate_ls || flagship->f_flag)
		return ;
	if (flagship->t_flag == true)
		ft_sortbytime(list, 0);
	else if (flagship->u_flag == true)
		ft_sortbytime(list, 1);
	else
		ft_sortbyascii(list);
	if (flagship->r_flag == true)
		ft_reverselist(list);
	list->current = list->head;
	return ;
}
