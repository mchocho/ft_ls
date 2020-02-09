/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 14:20:09 by mchocho           #+#    #+#             */
/*   Updated: 2020/02/09 16:06:58 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		ft_verifyflag(char *flag, flagobject *flagship)
{
	if (ft_strlen(flag) < 2 || flag[0] != '-')
		flagship->isvalid = false;
	else if (ft_stristr(flag, "--") == 0)
	{
		flagship->terminate_ls = true;
		ft_errormessage(0, '-', "");
	}
	else
		ft_assembleflagship(flag, flagship);
	return ;
}

static void		ft_validator(flagobject *fs, int ac, char **av, int *path)
{
	int			i;

	i = 0;
	while (i < ac)
	{
		if (ft_strlen(av[i]) > 1 && av[i][0] == '-')
		{
			ft_verifyflag(av[i], fs);
			if (fs->terminate_ls == true)
				return ;
		}
		else if (ft_isdrl(av[i]))
			*path = true;
		i++;
	}
}

static void		ft_checkerrors(flagobject *fs, int ac, char **av, int path)
{
	int			i;

	if (fs->terminate_ls == true)
		return ;
	i = 0;
	while (i < ac)
	{
		if (!(ft_strlen(av[i]) > 1 && av[i][0] == '-') && !ft_isdrl(av[i]))
		{
			ft_errormessage(404, 0, av[i]);
			if (path != true)
				fs->terminate_ls = true;
		}
		i++;
	}
	return ;
}

void			ft_ls(int argc, char **argv)
{
	flagobject	*flagship;
	int			pathtargeted;
	int			i;

	i = 0;
	pathtargeted = false;
	if (!(flagship = (flagobject*)malloc(sizeof(flagobject))))
		return ;
	ft_initflagobject(flagship);
	ft_validator(flagship, argc, argv, &pathtargeted);
	ft_checkerrors(flagship, argc, argv, pathtargeted);
	if (flagship->terminate_ls == true)
		return ;
	ft_scandetector(flagship, argc, argv, pathtargeted);
	ft_destroyflagship(&flagship);
	return ;
}

int				main(int argc, char **argv)
{
	if (argc > 1)
		ft_ls(argc - 1, argv + 1);
	else
	{
		argv[1] = ".";
		ft_ls(1, (argv + 1));
	}
	return (0);
}
