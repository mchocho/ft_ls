/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_totalblocks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:17:07 by mchocho           #+#    #+#             */
/*   Updated: 2019/07/24 16:44:17 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int ft_totalblocks(char *path)
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
			ft_putstr("ERR in ft_totalblocks: not a directory");
			return (result);
		}
	}
	while ((entry = readdir(directory)))
	{
		if (ft_isdir(entry))
			result += ft_totalblocks(ft_strjoin(path, entry->d_name));
		else if (ft_detectfiletype(entry) == 'l'
				|| ft_detectfiletype(entry) == 'r')
		{
			if (ft_detectfiletype(entry) == 'r')
				if (stat(path, &fstat) < 0)
					return (result);
			else
				if (lstat(path, &fstat) < 0)
					return (result);
			result += fstat->st_blocks;
		}
	}
	return ((int)result);
}
