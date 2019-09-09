/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 13:09:18 by mchocho           #+#    #+#             */
/*   Updated: 2019/09/07 13:22:06 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_sortlist(LinkedList *list, flagobject *flagship)
{
	if (!flagship->isvalid || flagship->terminate_ls || flagship->f_flag)
	{
		ft_putstr("Flagship is not valid or list should not be sorted\n");
		return ;
	}
	
	if (flagship->t_flag == true)
		ft_sortbytime(list);
	else if (flagship->u_flag == true)
		ft_sortbynamethenaccess(list);
	else
		ft_sortbyascii(list);

	if (flagship->r_flag == true)
		ft_reverselist(list);
	return ;
}
