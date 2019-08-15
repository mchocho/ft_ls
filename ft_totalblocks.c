/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_totalblocks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:17:07 by mchocho           #+#    #+#             */
/*   Updated: 2019/08/15 11:55:13 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int ft_totalblocks(char *path, int all)
{
	DIR				*directory;
	struct dirent	*entry;
	struct stat		fstat;
	blkcnt_t		result;

	result = 0;
	if (!(directory = opendir(path)))
	{
		if (ernno == 20)
		{
			ft_putstr("Not a directory");
			return (result);
		}
	}
	while ((entry = readdir(directory)))
	{
		if (!all && entry->d_name[0] == '.')
			continue;
		else if (ft_isdir(entry))
			result += ft_totalblocks(ft_strjoin(path, entry->d_name));
		else if (ft_detectfiletype(entry) == 'l'
				|| ft_detectfiletype(entry) == 'r')
		{
			if (ft_detectfiletype(entry) == 'r')
				if (stat(path, &fstat) < 0)
					continue;
			else
				if (lstat(path, &fstat) < 0)
					continue;
			result += fstat->st_blocks;
		}
	}
	closedir(directory);
	return ((int)result);
}
