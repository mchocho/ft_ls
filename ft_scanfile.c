/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:54:06 by mchocho           #+#    #+#             */
/*   Updated: 2019/09/07 13:21:17 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
  
int ft_isdrl(char *str)
{
	return (ft_strichr("drl", ft_detectfilepathtype(str)) > -1);
}

int ft_skiphiddenfiles(char *path, flagobject *flagship)
{
	return (!flagship->a_flag && !flagship->f_flag && *path && path[0] == '.');
}

int ft_skipnondirectories(char *path, flagobject *flagship)
{
	return (!ft_ispathdir(path) && flagship->d_flag);
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
			if (stat(entry->d_name, &fstat) < 0 /*|| ft_skiphiddenfiles(path, flagship) || (!(ft_ispathdir(entry->d_name) && flagship->d_flag))*/)
				continue;
			//^
			ft_addhead(list, entry->d_name, fstat.st_mtime, fstat.st_atime);
		}
		closedir(directory);
	}
	else
	{
		if (lstat(path, &fstat) < 0 || (!flagship->a_flag && path[0] == '.'))
			return ;
		ft_addhead(list, path, fstat.st_mtime, fstat.st_atime);
	}
	ft_putstr("Hello ft_sortlist()\n");
	ft_sortlist(list, flagship);
	ft_putstr("Goodbye ft_sortlist()\n");
	ft_printlist(list, flagship);
	if (dirdetected && ft_ispathdir(path) && flagship->R_flag)
	{
		if (!(directory = opendir(path)))
			return;
		while ((entry = readdir(directory)) && entry != NULL)
			if (ft_ispathdir(entry->d_name) && !ft_skiphiddenfiles(entry->d_name, flagship))
			{
				ft_putstr("\n\n");
				ft_scanfile(entry->d_name, flagship);
			}
		closedir(directory);
	}
	return ;
}

int main(int argc, char **argv)
{
	ft_putstr(" Testing ft_scanfile.c\n----------------------------------\n");

	char *foo;
	flagobject *flagship = (flagobject *)malloc(sizeof(flagobject));

	ft_initflagobject(flagship);

	flagship->l_flag = true;
	flagship->a_flag = true;
	flagship->f_flag = true;
	if (argc > 1)
		foo = argv[1];
	else foo = "./";

	ft_putstr("Scanning file: ");
	ft_putstr(foo);
	ft_putstr("\n\n");

	ft_scanfile(foo, flagship);

	return 0;

}
