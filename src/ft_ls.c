/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 14:20:09 by mchocho           #+#    #+#             */
/*   Updated: 2019/09/05 15:38:21 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*static int	ft_optionistarget(char *str)
{
	size_t len;
	
	len = ft_strlen(str);
	return ((len > 0 && str[0] != '-' ));
}*/

/*static void	ft_fileerror(char *str)
{
	ft_putstr("ls: ");
	ft_putstr(str);
	ft_putstr(": No such file or directory\n");
	return ;
}*/

/*char *ft_absolutepath(char *path)
{
	if (path[ft_strlen(path) - 1] != '/')
		ft_strcat(path, "/");
	return (path);
}*/

/*static int	ft_isdrl(struct stat *fstat)
{
	return (ft_strichr("drl", ft_filetype(fstat)) > -1);
}*/


static int      ft_isdrl(char *path)
{
        struct stat fstat;

        if (stat(path, &fstat) < 0)
                return (0);
        return (ft_strichr("drl", ft_filetype(&fstat)) > -1);
}

void	ft_ls(int argc, char **argv)
{
	//LinkedList	*list;
	flagobject	*flagship;
	int		pathtargeted;
	int		i;

	i = 0;
	pathtargeted = false;
	if (!(flagship = (flagobject*)malloc(sizeof(flagobject))))
		return ;
	ft_initflagobject(flagship);
	while (i < argc)
	{
		if (ft_strlen(argv[i]) > 1 && argv[i][0] == '-')// && !flagship->fod_exclusively)
		{
			ft_verifyflag(argv[i], flagship);
			if (flagship->terminate_ls == true)
				return ;
		} else if (ft_isdrl(argv[i]))
			pathtargeted = true;
		i++;
	}
	i = 0;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) > 1 && argv[i][0] == '-' && !ft_isdrl(argv[i]))
		{
			ft_putstr("ls: ");
			ft_putstr(str);
			ft_putstr(": No such file or directory\n");
		}
		i++;
	}
	i = 0;
	if (pathtargeted && argc)
		while (i < argc)
		{
			if (ft_strichr("dr", ft_detectfilepathtype(argv[i])) > -1)
				ft_scanfile(argv[i], flagship);
			i++;
		}
	else
		ft_scanfile("./", flagship);
	return ;
}

int main(int argc, char** argv)
{
	if (argc > 2)
		ft_ls(argc - 1, argv + 1);
	else
	{
		argv[1] = ".";
		ft_ls(1, (argv + 1));
	}
	return 0;
}
