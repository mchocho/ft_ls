/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:54:06 by mchocho           #+#    #+#             */
/*   Updated: 2019/09/10 16:11:58 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
  
int ft_isdrl(char *str)
{
	return (ft_strichr("drl", ft_detectfilepathtype(str)) > -1);
}

int ft_skiphiddenfiles(char *path, flagobject *flagship)
{
	return ((!flagship->f_flag && !flagship->a_flag) && path[0] == '.');
}

int ft_skipnondirectories(char *path, flagobject *flagship)
{
	return (!ft_ispathdir(path) && flagship->d_flag);
}

int ft_iscorpdir(char *str)
{
	return (ft_strcmp(ft_splicepath(str), ".") == 0 || ft_strcmp(ft_splicepath(str), "..") == 0);
}

void ft_scanfile(char *path, flagobject *flagship)
{
	DIR			*directory;
	LinkedList		*list;
	struct dirent		*entry;
	struct stat		fstat;
	int			dirdetected;
	t_file			*current;

	if (!ft_isdrl(path) || (!(list = (LinkedList *)malloc(sizeof(LinkedList)))))
		return;
	ft_initlist(list);
	dirdetected = false;
	if (ft_ispathdir(path))
	{
		if (!(directory = opendir(path)))
			return;
		while ((entry = readdir(directory)) && entry != NULL)
		{
			if (ft_ispathdir(entry->d_name) && !ft_iscorpdir(entry->d_name)) 
				dirdetected = true;
			if (lstat(entry->d_name, &fstat) < 0 || ft_skiphiddenfiles(ft_splicepath(entry->d_name), flagship))
				continue;
			ft_addtail(list, entry->d_name, fstat.st_mtime, fstat.st_atime);
		}
		closedir(directory);
	}
	else
	{
		if (lstat(path, &fstat) < 0)
			return ;
		ft_addtail(list, path, fstat.st_mtime, fstat.st_atime);
	}
	ft_sortlist(list, flagship);
	ft_printlist(list, flagship);
	if (dirdetected && ft_ispathdir(path) && flagship->R_flag)
	{
		current = list->head;
		while (current != NULL)
		{
			if (ft_ispathdir(current->filename)) {
				ft_putstr("\n\n");
				ft_putstr(path);
				ft_putstr(current->filename);
				ft_putstr(":\n");
				if (flagship->l_flag)
				{
					ft_putstr("Total: ");
					ft_totalblocks(current->filename, true);
					ft_putchar('\n');
				}
				ft_scanfile(ft_strjoin(path, current->filename), flagship);
			}
			current = current->next;
		}
	}
	ft_cleanlist(&list);
	return ;
}

int main(int argc, char **argv)
{
	/*
	if(argc > 1)
	{
		flagobject *flagship = (flagobject *)malloc(sizeof(flagobject));
		ft_initflagobject(flagship);
	
		ft_scanfile(argv[1], flagship);
	}
	ft_putchar('\n');
	*/
	ft_putstr(" Testing ft_scanfile.c\n----------------------------------\n");

	char *foo;
	flagobject *flagship = (flagobject *)malloc(sizeof(flagobject));

	ft_initflagobject(flagship);


	flagship->l_flag = true;
	flagship->a_flag = false;
	flagship->f_flag = false;
	flagship->R_flag = true;
	flagship->r_flag = false;
	flagship->t_flag = false;
	flagship->d_flag = false;
	flagship->u_flag = true;
	
	if (argc > 1)
		foo = argv[1];
	else foo = "./";

	ft_putstr("Scanning file: ");
	ft_putstr(foo);
	ft_putstr("\n\n");

	ft_scanfile(foo, flagship);

	return 0;

}
