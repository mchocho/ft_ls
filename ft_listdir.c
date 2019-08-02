/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 12:57:18 by mchocho           #+#    #+#             */
/*   Updated: 2019/08/02 16:20:47 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

void	ft_listdir(char *path, int all, int recursive, int longL)//, char sortby)
{
	DIR				*directory;
	struct dirent	*entry;

	if (!(directory = opendir(path)))
	{
		if (errno == 20)
			printf("Not a directory");
			//ft_putstr("Not a directory");
		return ;
	}

	while ((entry = readdir(directory)) && entry != NULL)
	{
		if (!all && entry->d_name[0] == '.')
			continue;

		if (recursive && ft_ispathdir(ft_strjoin(path, entry->d_name)))
		{
			//It's a recursive long list format
			ft_putstr(ft_strjoin(path, entry->d_name));
			ft_putstr(":\ntotal ");
			ft_putnbr(ft_totalblocks(ft_strjoin(path, entry->d_name)));
			ft_putchar('\n');
			ft_longlist(path, all);//, recursive, sortby);
		} else
			ft_putstr(entry->d_name);
	}
	closedir(directory);
	return ;
}

#include <stdio.h>

int main(int argc, char** argv)
{
	if (argc == 1)
		ft_listdir("./", FALSE, FALSE, FALSE);//, FALSE);
	else if (argc == 2)
		ft_listdir(argv[1], FALSE, FALSE, FALSE);


	return 0;

}
