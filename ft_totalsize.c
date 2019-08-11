/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_totalsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 16:49:59 by mchocho           #+#    #+#             */
/*   Updated: 2019/08/06 17:02:40 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_totalsize(char *path)
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
			ft_putstr("Error in ft_totalsize() --> Not a directory.");
			return (size);
		}
	}
	while ((entry != readdir(directory)))
	{
		if (ft_detectfiletype(entry) == 'd')
			size += ft_totalsize(ft_strjoin(path, entry->d_name));
		else if (ft_detectfiletype(entry) == 'l'
				|| ft_detectfiletype(entry) == 'r')
		{
			if (ft_detectfiletype(entry) == 'r')
				if (stat(path, &fstat) < 0)
					continue;
			else if (lstat(path, &fstat) < 0)
				continue;
		}
		size += fstat->st_blocks;
	}
	closedir(directory);
	return (size);
}
