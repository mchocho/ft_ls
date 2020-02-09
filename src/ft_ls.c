/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 14:20:09 by mchocho           #+#    #+#             */
/*   Updated: 2020/02/09 12:52:31 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

/*static void ft_errormessage(int err, char c, char *file)
{
	ft_putstr(RED);
	ft_putstr("ls: ");
	if (err == 0)
		ft_putstr("unknown option ");
	else if (err == 404)
	{
		ft_putstr("Cannot access '");
		ft_putstr(file);
		ft_putstr("': No such file or directory\n");
		return ;
	}
	else
		ft_putstr("illegal option ");	
	ft_putstr("-- ");
	ft_putchar(c);
	ft_putchar('\n');
	ft_putstr(NO_COL);
}*/

static int ft_handleoptions(char *flag, flagobject *flagship)
{
	int i;

	if (flagship == NULL)
		return false;
	i = 0;
	while(flag[i])
	{
		if (!ft_isvalidoption(flag[i]) || ft_strichr(flag, '-') > 1)
		{
			ft_errormessage(1, (ft_strichr(flag, '-') > 1) ? '-' : flag[i], "");
			flagship->terminate_ls = true;
			return (false);
		} else {
			ft_assembleflagship(flagship, flag[i]);
			/*if (flag[i] == 'l')
				flagship->l_flag = true;
			else if (flag[i] == 'r')
				flagship->r_flag = true;
			else if (flag[i] == 'R')
				flagship->R_flag = true;
			else if (flag[i] == 't')
				flagship->t_flag = true;
			else if (flag[i] == 'u')
				flagship->u_flag = true;
			else if (flag[i] == 'f')
				flagship->f_flag = true;
			else if (flag[i] == 'g')
				flagship->g_flag = true;
			else if (flag[i] == 'd')
				flagship->d_flag = true;
			else if (flag[i] == 'i')
				flagship->i_flag = true;
			else if (flag[i] == 'a')
				flagship->a_flag = true;
			else if (flag[i] == 'o')
				flagship->o_flag = true;*/
		}
		i++;
	}
	return (true);
}

static void	ft_verifyflag(char *flag, flagobject *flagship)
{
	if (ft_strlen(flag) < 2 || flag[0] != '-')
		flagship->isvalid = false;
	else if (ft_stristr(flag, "--") == 0)
	{
		flagship->terminate_ls = true;
		ft_errormessage(0, '-', "");
	}
	else
		ft_handleoptions(flag, flagship);
	return ;
}

void	ft_validator(flagobject *fs, int ac, char **av, int *path)
{
	int i;

	i = 0;
	while (i < ac)
	{
		if (ft_strlen(av[i]) > 1 && av[i][0] == '-')
		{
			ft_verifyflag(av[i], fs);
			if (fs->terminate_ls == true)
				return;
		} else if (ft_isdrl(av[i]))
			*path = true;
		i++;
	}
}

void	ft_ls(int argc, char **argv)
{
	flagobject	*flagship;
	int		pathtargeted;
	int		i;

	i = 0;
	pathtargeted = false;
	if (!(flagship = (flagobject*)malloc(sizeof(flagobject))))
		return ;
	ft_initflagobject(flagship);
	ft_validator(flagship, argc, argv, &pathtargeted);
	if (flagship->terminate_ls == true)
		return ;
	while (i < argc)
	{
		if (!(ft_strlen(argv[i]) > 1 && argv[i][0] == '-') && !ft_isdrl(argv[i]))
		{
			ft_errormessage(404, 0, argv[i]);
			if (pathtargeted != true)
				return ;
		}
		i++;
	}
	i = 0;
	if (pathtargeted && argc)
		while (i < argc)
		{
			if (ft_isdrl(argv[i]))
				ft_scanfile(argv[i], flagship);
			i++;
		}
	else
		ft_scanfile("./", flagship);
	ft_destroyflagship(&flagship);
	return ;
}

int main(int argc, char** argv)
{
	if (argc > 1)
		ft_ls(argc - 1, argv + 1);
	else
	{
		argv[1] = ".";
		ft_ls(1, (argv + 1));
	}
	return 0;
}
