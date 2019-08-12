/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 12:57:18 by mchocho           #+#    #+#             */
/*   Updated: 2019/08/12 18:06:37 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls(char *path, int all, int recursive, int longL, int sortby)
{
	DIR				*directory;
	struct dirent	*entry;
	int i;

	i = 0;
	if (!(directory = opendir(path)))
	{
		if (errno == 20)
			ft_putstr("Not a directory");
		return ;
	}
	while ((entry = readdir(directory)) && entry != NULL)
	{
		if (ft_chrcmp('t', sortby))
		{
			ft_printfiles_t(path, all, recursive, longL);
			break;
		}
		else if (ft_chrcmp('r', sortby))
		{
			ft_printfiles_r(path, all, recursive, longL);
			break;
		}
		else if (!all && entry->d_name[0] == '.')
			continue;
		else if (recursive && ft_ispathdir(ft_strjoin(path, entry->d_name)))
		{
			 ft_putstr(ft_strjoin(path, entry->d_name));
			 ft_putstr(":\n");
			 ft_ls(ft_strjoin(path, entry->d_name), all, true, longL, sortby);
		}
		else if (longL)
		{
			ft_putstr("total:\n");
			ft_putnbr(ft_totalblocks(ft_strjoin(path, entry->d_name)));
			ft_putchar('\n');
			ft_longlist(ft_strjoin(path, entry->d_name));
		}
		else
			ft_putstr(entry->d_name);
	}
	closedir(directory);
	return ;
}

#include <stdio.h>

int main(int argc, char** argv)
{
	if (argc == 1)
		ft_ls("./", false, false, false, false,);
	else if (argc == 2)
		ft_ls(argv[1], false, false, false, false);

	return 0;

}
