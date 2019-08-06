/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 12:57:18 by mchocho           #+#    #+#             */
/*   Updated: 2019/07/24 14:20:20 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

void	ft_listdir(char *path, int all, int recursive, int longL, char sortby)
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
		if (recursive && ft_isdir(ft_strjoin(path, entry->d_name)))
		{
			//It's a recursive long list format
			ft_putstr(ft_strjoin(path, entry->d_name));
			ft_putstr(":\ntotal ");
			ft_putendl(ft_itoa(ft_totalblocks(ft_strjoin(path, entry->d_name))));
			ft_longlist(path, all, recursive, sortby);
		} else if (!all && entry->d_name[0] == '.')
			continue;
		//else if ()
		printf("%s\n", entry->d_name);
		//ft_putstr(entry->d_name);
	}
	closedir(directory);
	return ;
}

#include <stdio.h>

int main(int argc, char** argv)
{
	printf(" Testing ft_listdir.c\n--------------------------\n");

	if (argc == 2)
		ft_listdir(argv[1], 1);

	return 0;

}
