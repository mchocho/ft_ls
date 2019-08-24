/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_totalsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 17:32:16 by mchocho           #+#    #+#             */
/*   Updated: 2019/08/19 17:34:57 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

off_t	ft_totalsize(char *path, int all)
{
	DIR				*directory;
	struct dirent	*entry;
	struct stat		fstat;
	off_t		result;

	result = 0;
	if (ft_detectfilepathtype(path) == 'l'
			|| ft_detectfilepathtype(path) == 'r')
	{
			if (lstat(path, &fstat) < 0)
					return (0);
			return (fstat.st_size);
	}
	else if (ft_ispathdir(path))
	{
		if (!(directory = opendir(path)))
			return (0);	
		while ((entry = readdir(directory)))
		{
			if (!all && entry->d_name[0] == '.')
				continue;
			else
				result += ft_totalsize(entry->d_name, all);
		}
		closedir(directory);
	}
	return (result);
}
/*
#include <stdio.h>

int main()
{
	printf(" Testing ft_totalsize.c\n--------------------------------\n");

	char *foo = "./ft_addtail.c";

	printf("Block size of file \"%s\": %lld", foo, ft_totalsize(foo, true));

	return (0);
}*/
