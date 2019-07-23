/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 12:57:18 by mchocho           #+#    #+#             */
/*   Updated: 2019/07/23 16:02:44 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_listdir(char *path, int all)
{
	DIR				*directory;
	struct dirent	*entry;

	if (!(directory = open(path)))
	{
		if (errno == 20)
			ft_putstr("Not a directory");
		return ;
	}

	while ((entry = readdir(directory)) && entry != NULL)
	{
		if (!all && entry->dname == '.')
			continue;
		ft_putstr(entry->);
	}
	closedir(path);
	return ;
}
