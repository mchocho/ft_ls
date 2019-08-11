/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printusername.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 09:48:46 by mchocho           #+#    #+#             */
/*   Updated: 2019/08/06 16:17:49 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printusername(char *path)
{
	struct stat		fstat;
	struct passwd		*pw;
	
	if (ft_detectfilepathtype(path) == 'l')
		if (lstat(path, &fstat) < 0)
			return ;
	else if (ft_detectfilepathtype(path) == 'r')
		if (stat(path, &fstat) < 0)
			return ;
	if ((pw = getpwuid(fstat.st_uid)))
		ft_putstr(pw->pw_name);
	return ;
}
