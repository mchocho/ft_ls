/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filecount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 17:39:03 by mchocho           #+#    #+#             */
/*   Updated: 2019/07/23 17:58:22 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_filecount(DIR folder, int all)
{
	DIR				*directory;
	struct dirent	*entry;
	int				count;

	if (!(directory = opendir(path)))
	{
		if (ernno == 20)
			ft_putstr("Not a directory");
	}

	while ((entry = readdir(directory)))
	{
		if (!all && entry->d_name[0] == '.')
			continue;
		i++;
	}
	closedir(directory);
	return (i);
}
