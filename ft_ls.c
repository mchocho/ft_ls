/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 12:57:18 by mchocho           #+#    #+#             */
/*   Updated: 2019/08/19 17:27:59 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_optionistarget(char *str)
{
	size_t len;
	
	len = ft_strlen(len)
	return ((len == 1 && str[0] == '-') || (len > 0 && str[0] != '-'));
}

void	ft_fileerror(char *str)
{
	ft_putstr("ls: ");
	ft_putstr(str);
	ft_putstr(": No such file or directory\n");
	return ;
}


void	ft_ls(int argc, char **argv)//char *path, int all, int recursive, int longL, int sortby)
{
	LinkedList	*list;
	flagobject	*flagship;
	int		pathtargeted;
	int		i;

	i = 0;
	pathtargeted = false;
	if (!(flagship = (*flagobject)malloc(sizeof(flagobject))))
		return ;
	if (!(list = (LinkedList *)malloc(sizeof(LinkedList))))
		return ;
	ft_initflagobject(flagship);
	ft_initlist(list);

	while (i < argc)
	{
		if (ft_strlen(argv[i]) > 1 && argv[i][0] == '-')// && !flagship->fod_exclusively)
		{
			if (!flagship->fod_exclusively)	
			{
				ft_verifyflag(argv[i], flagship);
				flagship->fod_fromindex = i - 1;
			}
			if (flagship->terminate_ls == true)
				return ;
		}
		i++;
	}
	i = 0;
	while (i < argc)
	{
		if (ft_optionistarget(argv[i]) && ft_strichr("dr", ft_detectfilepathtype(argv[i])) > -1)
		{
			ft_filerror(argv[i]);
			pathtargeted = true;
		}
		i++;
	}
	ft_sortlist(list);
	
	/*DIR				*directory;
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
		else if (recursive && ft_ispathdir(entry->d_name))
		{
			 ft_putstr(entry->d_name);
			 ft_putstr(":\n");
			 ft_ls(entry->d_name, all, true, longL, sortby);
		}
		else if (longL)
		{
			ft_putstr("total:\n");
			ft_putnbr(ft_totalblocks(ft_strjoin(path, entry->d_name)));
			ft_putchar('\n');
			ft_longlist(ft_strjoin(path, entry->d_name), all);
		}
		else
			ft_putstr(entry->d_name);
	}
	closedir(directory);*/
	

	return ;
}

int main(int argc, char** argv)
{
	if (argc == 1)
		ft_ls("./", false, false, false, false);
	else if (argc == 2)
		ft_ls(argv[1], false, false, false, false);

	return 0;

}
