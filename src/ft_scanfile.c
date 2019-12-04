/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:54:06 by mchocho           #+#    #+#             */
/*   Updated: 2019/09/17 16:47:13 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
  
static int	ft_isdrl(char *path)
{
	struct stat fstat;

	if (stat(path, &fstat) < 0)
		return (0);
	return (ft_strichr("drl", ft_filetype(&fstat)) > -1);
}

static int	ft_ispathdir(char *path)
{
	struct stat fstat;

	if (stat(path, &fstat) < 0)
		return (0);
	return (S_ISDIR(fstat.st_mode));
}

static int	ft_skipfile(char *path, flagobject *flagship)
{
	char *fn;

	if (flagship->d_flag)
		return (ft_ispathdir(path) ? false : true);
	fn = ft_splicepath(path);
	return (!flagship->f_flag && !flagship->a_flag && fn[0] == '.');
}

/*static int	ft_iscorpdir(t_file *file)
{
	char *str;
	if (ft_filetype(file->file_status) != 'd')
		return (false);
	ft_putendl("\nHello ft_iscorpdir()");
	if (ft_strcmp(file->filename, "./") == 0)
		return (true);
	str = ft_splicepath(file->filename);
	ft_putstr("ft_iscorpdir splicepath returned url: ");
	ft_putendl(str);
	return (ft_strcmp(str, ".") == 0 || ft_strcmp(str, "..") == 0);
}*/

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
			//ft_putendl(absp);
			if (lstat(absp, &fstat) < 0 || ft_skipfile(absp, flagship))
				continue;
			ft_addtail(list, absp, &fstat);
			ft_strcleandel(&absp);
		}
		closedir(directory);
	}
	else
	{
		if (lstat(path, &fstat) < 0)
			return ;
		ft_addtail(list, path, &fstat);
	}
	//ft_sortlist(list, flagship);
	if (flagship->l_flag || flagship->g_flag)
	{
		ft_putstr("total ");
                //ft_putnbr((int)(file->file_status->st_blksize));
                ft_putchar('\n');
	}
	ft_printlist(list, flagship);
	if (ft_ispathdir(path) && flagship->R_flag)
	{
		list->current = list->head;
		while (list->current != NULL)
		{
			absp = list->current->filename;//ft_strjoin(ft_parseurl(path), ft_splicepath(list->current->filename));
			if (ft_ispathdir(absp) && !ft_skipfile(absp, flagship) && !ft_iscorpdir(list->current->filename)) {
				absp = ft_strjoin(ft_parseurl(path), ft_splicepath(list->current->filename));
				ft_putstr("\n\n'");
				ft_putstr(/*ft_strippath(*/absp/*)*/);
				ft_putstr("':\n");
				/*if (flagship->l_flag)
				{
					ft_putstr("Total: ");
					//ft_totalsize(absp, true);
					ft_putchar('\n');
				}*/
				ft_scanfile(absp, flagship);
				ft_strcleandel(&absp);
			}
			list->current = list->current->next;
		}
	}
	//ft_putendl("Cleaning the linked list");
	ft_cleanlist(&list);
	//ft_putendl("And we're done cleaning the list!");
	return ;
}

/*int main(int argc, char **argv)
{
	ft_putstr(" Testing ft_scanfile.c\n----------------------------------\n");

	char *foo;
	flagobject *flagship = (flagobject *)malloc(sizeof(flagobject));

	ft_initflagobject(flagship);
	
	flagship->l_flag = false;
	flagship->a_flag = true;
	flagship->f_flag = false;
	flagship->R_flag = true;
	flagship->r_flag = false;
	flagship->t_flag = false;
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
