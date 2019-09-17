/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:05:23 by mchocho           #+#    #+#             */
/*   Updated: 2019/09/10 15:51:51 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_longlist(char *path, flagobject *flagship)
{
	int all;
	
	all = flagship->a_flag;
	//Print file permissions
	ft_printpermissions(path);
	ft_putchar(' ');
	//Print # of hardlinks
	if (ft_ispathdir(path))
		ft_putnbr(ft_hardlinkcount(path, all, true));//ft_filecount(path, all));
	else
		ft_putpaddedstr("1", 10);
	ft_putchar(' ');
	//Print username
	ft_printusername(path);
	ft_putchar(' ');
	//Print groupname
	ft_printgroupname(path);
	ft_putchar(' ');
	//Print total file/directory size
	ft_putnbr((int)ft_totalsize(path, all));
	ft_putchar(' ');
	//Print date and time
	ft_printdatetime(path);
	ft_putchar(' ');
	//Print file/directory name
	ft_putstr(ft_splicepath(path));		//Remove path reference
	ft_putchar('\n');
}
