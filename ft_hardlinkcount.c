/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hardlinkcount.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 23:40:16 by mchocho           #+#    #+#             */
/*   Updated: 2019/08/17 09:59:43 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int ft_hardlinkcount(char *path, int all, int recursive)
{
	DIR				*directory;
	struct dirent	*entry;
	struct stat		fstat;	
	int				hardlink_c;

	hardlink_c = 0;

	if (ft_ispathdir(path))
	{
		if (!(directory = opendir(path)))
			return (1);
		while ((entry = readdir(directory)))
		{
			//if (!all && entry->d_name[0] == '.')
			//	continue;
			//hardlink_c += ft_hardlinkcount(ft_strcat(ft_strcat(path, "/"), entry->d_name), all);
			hardlink_c += ft_hardlinkcount(/*ft_strcat(path, */entry->d_name/*)*/, all, false);
			if (recursive == false)
				break;
		}
	}
	else if (lstat(path, &fstat) > 0)
		hardlink_c = (int)fstat.st_nlink;
	else if (stat(path, &fstat) > 0)
		hardlink_c = (int)fstat.st_nlink;

	if (hardlink_c == 0)
		return (1);
	return (hardlink_c);
}
