/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filecount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 17:39:03 by mchocho           #+#    #+#             */
/*   Updated: 2020/02/09 10:45:26 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		ft_filecount(char *path, int all)
{
	DIR				*directory;
	struct dirent	*entry;
	int				count;

	count = 0;
	if (!(directory = opendir(path)))
	{
		return (1);
		if (errno == 20)
		{
			ft_putstr(RED);
			ft_putstr("Not a directory");
			ft_putstr(NO_COL);
		}
	}
	while ((entry = readdir(directory)))
	{
		if (!all && entry->d_name[0] == '.')
			continue;
		count++;
	}
	closedir(directory);
	if (count == 0)
		count = 1;
	return (count);
}
