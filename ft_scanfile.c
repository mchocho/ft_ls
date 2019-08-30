/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:54:06 by mchocho           #+#    #+#             */
/*   Updated: 2019/08/29 18:48:05 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
  
int ft_isdrl(char *str)
{
	return (ft_strichr("drl", ft_detectfilepathtype(str)) > -1);
}

void ft_scanfile(char *path, flagobject *flagship)
{
	DIR				*directory;
	LinkedList		*list;
	struct dirent	*entry;
	struct stat		fstat;
	int				dirdetected;

	if (!ft_isdrl(path) || (!(list = (LinkedList *)malloc(sizeof(LinkedList)))))
		return;
	ft_initlist(list);
	dirdetected = false;
	if (ft_ispathdir(path))
	{
		if (!(directory = opendir(path)))
			return;
		while((entry = readdir(directory)) && entry != NULL)
		{
			if (ft_ispathdir(entry->d_name))
				dirdetected = true;
			if (lstat(path, &fstat) < 0 || (!flagship->a_flag && path[0] == '.'))
				continue;
			ft_addhead(list, entry->d_name, ft_constructctimeobj(fstat.st_mtime));
		}
		closedir(directory);
	}
	else
	{
		if (lstat(path, &fstat) < 0) || (!flagship->a_flag && path[0] == '.')
			return ;
		ft_addhead(list, path, ft_constructctimeobj(fstat.st_mtime));
	}
	ft_sortlist(list, flagship);
	ft_printlist(list, flagship);
	if (dirdetected == true && ft_ispathdir(path))
	{
		if (!(directory = opendir(path)))
			return;
		while ((entry = readdir(directory)) && entry != NULL)
			if (ft_ispathdir(entry->d_name))
			{
				ft_putstr("\n\n");
				ft_scanfile(entry->d_name, flagship);
			}
		closedir(directory);
	}
	return ;
}
