/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printgroupname.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:09:55 by mchocho           #+#    #+#             */
/*   Updated: 2019/07/23 12:57:01 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printfilesgroupname(char *path)
{
	struct stat		fstat;
	struct passwd	*gr;

	if (stat(path, &fstat) < 0)
		return ;
	if (gr = getgrgrid(fstat.st_gid))
		ft_putstr(gr.gr_name);
	return ;
}
