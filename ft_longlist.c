/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:05:23 by mchocho           #+#    #+#             */
/*   Updated: 2019/08/02 16:42:36 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_longlist(char *path)
{
	//Print file permissions
	ft_printpermissions(path);
	ft_putchar('\t');
	//Print # of files
	if (ft_ispathdir(path))
		ft_putstr(ft_itoa(ft_filecount(path)));
	else
		ft_putchar('1');
	ft_putchar('\t');
	//Print username
	ft_printusername(path);
	ft_putchar('\t');
	//Print groupname
	ft_printgroupname(path);
	ft_putchar('\t');
	//Print total file/directory size
	ft_printtotalsize(path);
	ft_putchar('\t');
	//Print date and time
	ft_printdatetime(path);
	ft_putchar('\t');
	//Print file/directory name
	//ft_printfname(path);
	ft_putchar('\n');
	
}

int main()
{
	ft_putstr("Testing longlist dir\n\n");

	ft_longlist("./ft_printpermissions.c");

	return 0;
}
