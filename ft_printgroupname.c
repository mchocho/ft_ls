/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printgroupname.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:09:55 by mchocho           #+#    #+#             */
/*   Updated: 2019/08/06 14:12:07 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printgroupname(char *path)
{
	struct stat		fstat;
	struct group		*gr;

	if (ft_detectfilepathtype(path) == 'l')
	{	if (lstat(path, &fstat) < 0)
			return ;
	}
	if (ft_detectfilepathtype(path) == 'r')
	{
		if (stat(path, &fstat) < 0)
			return ;

	}
	if ((gr = getgrgid(fstat.st_gid)))
		ft_putstr(gr->gr_name);}
	return ;
}
