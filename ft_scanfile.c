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
  
static int	ft_isdrl(char *str)
{
	return (ft_strichr("drl", ft_detectfilepathtype(str)) > -1);
}

static int	ft_skipfile(char *path, flagobject *flagship)
{
	char *fn;

	if (flagship->d_flag)
		return (ft_ispathdir(path) ? false : true);
	fn = ft_splicepath(path);
	return (!flagship->f_flag && !flagship->a_flag && fn[0] == '.');
}

/*
static int	ft_skiphiddenfiles(char *path, flagobject *flagship)
{
	if (flagship->d_flag && )
	
	return ((!flagship->f_flag && !flagship->a_flag) && ft_splicepath(path)[0] == '.');
}

static int	ft_skipnondirs(char *path, flagobject *flagship)
{
	return (!ft_ispathdir(path) && flagship->d_flag);
}
*/

static int	ft_iscorpdir(char *path)
{
	char *str;
	if (!ft_ispathdir(path))
		return (false);
	if (ft_strcmp(path, "./") == 0)
		return (true);
	str = ft_splicepath(path);
	return (ft_strcmp(str, ".") == 0 || ft_strcmp(str, "..") == 0);
}

void ft_scanfile(char *path, flagobject *flagship)
{
	DIR			*directory;
	LinkedList		*list;
	struct dirent		*entry;
	struct stat		fstat;
	char			*absp;

	if (!ft_isdrl(path) || (!(list = (LinkedList *)malloc(sizeof(LinkedList)))))
		return ;
	ft_initlist(list);
	if (ft_ispathdir(path))
	{
		if (!(directory = opendir(path)))
			return ;
		while ((entry = readdir(directory)) != NULL)
		{
			absp = ft_strjoin(ft_parseurl(path), ft_splicepath(entry->d_name));
			if (lstat(absp, &fstat) < 0 || ft_skipfile(absp, flagship))
				continue;
			ft_addtail(list, absp, fstat.st_mtime, fstat.st_atime);
			ft_strcleandel(&absp);
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
	if (ft_ispathdir(path) && flagship->R_flag)
	{
		list->current = list->head;
		while (list->current != NULL)
		{
			if (ft_ispathdir(list->current->filename) && !ft_skipfile(list->current->filename, flagship) && !ft_iscorpdir(list->current->filename)) {
				absp = ft_strjoin(ft_parseurl(path), ft_splicepath(list->current->filename));
				ft_putstr("\n\n");
				ft_putstr(absp);
				ft_putstr(":\n");
				if (flagship->l_flag)
				{
					ft_putstr("Total: ");
					ft_totalsize(absp, true);
					ft_putchar('\n');
				}
				ft_scanfile(absp, flagship);
			}
			list->current = list->current->next;
		}
	}
	ft_cleanlist(&list);
	return ;
}

/*
int main(int argc, char **argv)
{
	ft_putstr(" Testing ft_scanfile.c\n----------------------------------\n");

	char *foo;
	flagobject *flagship = (flagobject *)malloc(sizeof(flagobject));

	ft_initflagobject(flagship);

	flagship->l_flag = true;
	flagship->a_flag = false;
	flagship->f_flag = false;
	flagship->R_flag = true;
	flagship->r_flag = true;
	flagship->t_flag = true;
	flagship->d_flag = false;
	flagship->u_flag = false;
	
	if (argc > 1)
		foo = argv[1];
	else foo = "./";

	ft_putstr("Scanning file: ");
	ft_putstr(foo);
	ft_putstr("\n\n");

	ft_scanfile(foo, flagship);

	return 0;
}*/
