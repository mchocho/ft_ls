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

#include "../includes/ft_ls.h"

static void ft_errormessage(int err, char c, char *file)
{
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
}

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
			if (flag[i] == 'l')
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

static int      ft_isdrl(char *path)
{
        struct stat fstat;

        if (stat(path, &fstat) < 0)
                return (0);
        return (ft_strichr("drl", ft_filetype(&fstat)) > -1);
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
	while (i < argc)
	{
		if (ft_strlen(argv[i]) > 1 && argv[i][0] == '-')
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
