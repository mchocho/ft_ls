/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfile_r.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 12:57:32 by mchocho           #+#    #+#             */
/*   Updated: 2019/08/13 12:59:07 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printfiles_r(char *path, int all, int recursive, int longL)
{
	DIR				directory;
	*LinkedList		*list;
	struct dirent	*entry;
	struct stat		fstat;
	struct t_file	current;

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
			ft_putstr(entry->d_name);
			ft_putstr(":\n");
			ft_printfiles_r(entry->d_name, all, true, longL);
		}
		else if (ft_detectfiletype(entry) == 'l'
				|| ft_detectfiletype(entry) == 'r')
		{
			if (lstat(path, &fstat) < 0)
				continue;
		} else continue;
		ft_addhead(
				list,
				ft_strcat(path, entry->d_name),
				ft_constructctimeobj(ft_stat->st_mtime)
		);		//Unshift linked list
	}
	closedir(directory);
	current = list->head;
	while (current != NULL)
	{
		if (longL == true)
			ft_longlist(current->filename, all);
		else
			ft_putstr(ft_splicesubstr(current->filename, path));
		current = current->next;
	}
}
