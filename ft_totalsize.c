/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_totalsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 16:49:59 by mchocho           #+#    #+#             */
/*   Updated: 2019/07/31 14:43:21 by mchocho          ###   ########.fr       */
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
			ft_putchar("Error in ft_totalsize() --> Not a directory.");
		}
	}
	while ((entry != readdir(directory)))
	{
		if (ft_detectfiletype(entry) == 'd')
			result += ft_totalsize(ft_strjoin(path, entry->d_name));
		else if (ft_detectfiletype(entry) == 'l'
				|| ft_detectfiletype(entry) == 'r')
		{
			if (ft_detectfiletype(entry) == 'r')
				if (stat(path, &fstat) < 0)
					return (result);
			else if (lstat(path, &fstat) < 0)
				return (result);
		}
		result += fstat->st_blocks;
	}
	closedir(directory);
	return (result);
}
