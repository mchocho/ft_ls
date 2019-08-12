/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfile_r.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 12:57:32 by mchocho           #+#    #+#             */
/*   Updated: 2019/08/12 18:06:41 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printfiles_r(char *path, int all, int recursive, int longL)
{
	DIR directory;
	*LinkedList *list;
	struct dirent *entry;
	struct stat fstat;

	if (!(directory = opendir(path)))
	{
		if (errno == 20)
			ft_putstr("Not a directory");
		return ;
	}
	list = (LinkedList*)malloc(sizeof(LinkedList));
	ft_initlist(list);	//Initialize linked list
	//current = (t_file*)malloc(sizeof(t_file));
	while ((entry = readdir(directory)) && entry != NULL)
	{
		if (!all && entry->d_name[0] == '.')
			coninue;
		else if (recursive && ft_ispathdir(ft_strjoin(path, entry->d_name)))
		{
			ft_putstr(ft_strjoin(path, entry->d_name));
			ft_printfiles_r(ft_strjoin(path, entrt->d_name), all, true, longL);
		}
		else if (ft_detectfiletype(entry) == 'l' || ft_detectfiletype(entry) == 'r')
		{
			if (lstat(path, &fstat) < 0)
				continue;
		} else continue;
		ft_addhead(
				list,
				ft_strcat(path, -> d_name),
				ft_constructctimeobj(ft_stat->st_mtime)
		);		//Unshift linked list
	}
	closedir(directory);
}
