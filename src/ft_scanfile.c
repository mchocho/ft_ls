/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:54:06 by mchocho           #+#    #+#             */
/*   Updated: 2020/02/09 16:27:31 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int		ft_skipfile(char *path, flagobject *flagship)
{
	char			*fn;

	if (flagship->d_flag)
		return (ft_ispathdir(path) ? false : true);
	fn = ft_splicepath(path);
	return (!flagship->f_flag && !flagship->a_flag && *fn == '.');
}

static int		ft_iscorpdir(char *path)
{
	char			*str;

	if (!ft_ispathdir(path))
		return (false);
	if (ft_strcmp(path, "./") == 0)
		return (true);
	str = ft_splicepath(path);
	return (ft_strcmp(str, ".") == 0 || ft_strcmp(str, "..") == 0);
}

static int		ft_readdir(List *list, char *path, flagobject *fs, char **s)
{
	DIR				*directory;
	struct dirent	*entry;
	struct stat		fstat;

	if (ft_ispathdir(path))
	{
		if (!(directory = opendir(path)))
			return (0);
		while ((entry = readdir(directory)) != NULL)
		{
			*s = ft_strjoin(ft_parseurl(path), ft_splicepath(entry->d_name));
			if (!(lstat(*s, &fstat) < 0) && !(ft_skipfile(*s, fs)))
				ft_addtail(list, *s, &fstat);
			ft_strcleandel(&*s);
		}
		closedir(directory);
	}
	else
	{
		if (lstat(path, &fstat) < 0)
			return (0);
		ft_addtail(list, path, &fstat);
	}
	return (1);
}

static int		ft_recursiveaction(flagobject *fs, char *s)
{
	return (!ft_skipfile(s, fs) && !ft_iscorpdir(s));
}

void			ft_scanfile(char *path, flagobject *flagship)
{
	List			*list;
	char			*absp;

	if (!ft_isdrl(path) || (!(list = (List *)malloc(sizeof(List)))))
		return ;
	ft_initlist(list);
	ft_readdir(list, path, flagship, &absp);
	ft_sortlist(list, flagship);
	ft_printlist(list, flagship);
	if (ft_ispathdir(path) && flagship->R_flag)
		while (list->current != NULL)
		{
			absp = list->current->filename;
			if (ft_ispathdir(absp) && ft_recursiveaction(flagship, absp))
			{
				absp = ft_strjoin(ft_parseurl(path), ft_splicepath(absp));
				ft_putstr(absp);
				ft_putendl(":");
				ft_scanfile(absp, flagship);
				ft_strcleandel(&absp);
			}
			list->current = list->current->next;
		}
	ft_cleanlist(&list);
	return ;
}
