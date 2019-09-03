/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 13:09:18 by mchocho           #+#    #+#             */
/*   Updated: 2019/09/03 12:53:24 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_sortlist(LinkedList *list, flagobject *flagship)
{
	if (!flagship->isvalid || flagship->terminate_ls || flagship->f_flag)
		return ;
	
	if (flagship->t_flag)
		ft_sortbytime(list);
	else if (flagship->u_flag)
		ft_sortbynamethenaccess(list);
	else
		ft_sortbyascii(list);

	if (flagship->r_flag)
		ft_reverselist(list);
	return ;
}
