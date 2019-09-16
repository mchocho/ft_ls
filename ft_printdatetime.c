/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdatetime.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:08:06 by mchocho           #+#    #+#             */
/*   Updated: 2019/08/09 16:08:47 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void ft_printdatetime(char *path)
{
	struct stat 	fstat;
	char			**timearr;
	char			*lastmodified;

	if (ft_detectfilepathtype(path) == 'r')
	{
		if (stat(path, &fstat) < 0)
			return ;
	} else if (ft_detectfilepathtype(path) == 'l')
	{
		if (lstat(path, &fstat) < 0)
			return ;
	} else return ;

	if (!(lastmodified = ctime(&fstat.st_mtime)))
		return ;
	timearr = ft_strsplit(lastmodified, ' ');
	ft_putstr(timearr[1]);
	ft_putchar(' ');
	ft_putstr(timearr[2]);
	ft_putchar(' ');
	ft_putstr(ft_strsplit(timearr[3], ':')[0]);
	ft_putchar(':');
	ft_putstr(ft_strsplit(timearr[3], ':')[1]);
	return ;
}
