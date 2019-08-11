/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filecount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 17:39:03 by mchocho           #+#    #+#             */
/*   Updated: 2019/08/06 15:53:45 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_filecount(char *path, all)
{
	DIR				*directory;
	struct dirent	*entry;
	int				count;

	count = 0;
	if (!(directory = opendir(path)))
	{
		if (ernno == 20)
			ft_putstr("Not a directory");
	}

	while ((entry = readdir(directory)))
	{
		if (!all && entry->d_name[0] == '.')
			continue;
		count++;
	}
	closedir(directory);
	if (count == 0)
		count = 1;
	return (count);
}
