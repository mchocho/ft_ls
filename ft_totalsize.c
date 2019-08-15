/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_totalsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 16:49:59 by mchocho           #+#    #+#             */
/*   Updated: 2019/08/15 13:49:58 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_totalsize(char *path, int all)
{
	DIR				*directory;
	struct dirent	*entry;
	struct stat		fstat;
	int				size;

	size = 0;
	if (!(directory = opendir(path)))
	{
		if (errno == 20)
		{
			//ft_putstr("Not a directory.");
			return (size);
		}
	}
	while ((entry = readdir(directory)))
	{
		if (!all && entry->d_name[0] == '.')
			continue;
		else if (ft_detectfilepathtype(ft_strcat(path, entry->d_name)) == 'd')
			size += ft_totalsize(ft_strcat(path, entry->d_name), all);
		else if (ft_detectfilepathtype(ft_strcat(path, entry->d_name)) == 'l'
				|| ft_detectfilepathtype(ft_strcat(path, entry->d_name)) == 'r')
		{
			if (ft_detectfilepathtype(ft_strcat(path, entry->d_name)) == 'r')
			{
				if (stat(path, &fstat) < 0)
					continue;
			} else if (lstat(path, &fstat) < 0)
				continue;
		}
		size += fstat.st_blocks;
	}
	closedir(directory);
	return (size);
}
