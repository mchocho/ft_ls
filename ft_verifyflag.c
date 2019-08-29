/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verifyflag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchocho <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 16:33:43 by mchocho           #+#    #+#             */
/*   Updated: 2019/08/26 15:51:36 by mchocho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void ft_errormessage(int err, char c)
{
	ft_putstr("ls: ");
	if (err == 0)
		ft_putstr("unknown option ");
	else
		ft_putstr("illegal option ");	
	ft_putstr("-- ");
	ft_putchar(c);
	ft_putchar('\n');
}


static void ft_initflagobject(flagobject *flagship)
{
	flagship->l_flag = false;
	flagship->r_flag = false;
	flagship->R_flag = false;
	flagship->t_flag = false;
	flagship->a_flag = false;
	flagship->fod_exclusively = false;
	flagship->isvalid = true;
	flagship->terminate_ls = false;
}

static int ft_handleoptions(char *flag, flagobject *flagship)
{
	int i;
	
	i = 0;
	while(flag[i])
	{
		if (!ft_isvalidoption(flag[i]) || ft_strichr(flag, '-') > 1)
		{
			ft_errormessage(1, (ft_strichr(flag, '-') > 1) ? '-' : flag[i]);
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
		}
		i++;
	}
	return (true);
}


flagobject *ft_verifyflag(char *flag, flagobject *flagship)
{
	//flagobject	*flagship;
	int		len;
	//int		dashcount;
	//int		i;

	//if(!(flagship = (flagobject *)malloc(sizeof(flagobject))))
	//	return (NULL);
	len = ft_strlen(flag);
	//dashcount = 0;
	//i = 0;
	ft_initflagobject(flagship);

	if (len < 2 || flag[0] != '-')
		flagship->isvalid = false;
	else if (ft_stristr(flag, "--") == 0)
		if (len == 2)
			flagship->fod_exclusively = true;
<<<<<<< HEAD
			return (flagship);
		}
		else {
			flagship->terminate_ls = true;
			ft_errormessage(0, '-');
			return (flagship);
		}
		/*else if (ft_isvalidoption(flag[3]) && len == 3)
		{
			//if (flag[3] == '[')
			//	return (ft_handlebrackets(ft_strchr('['), flagship));
			else if (flag[3] == 'g')
				flagship->terminate_ls = true;
			else
			{
				ft_errormessage(0, );
			}
		}
		else if ()*/
	}
=======
		else
		{
			flagship->terminate_ls = true;
			ft_errormessage(0, '-');
		}
	else
		ft_handleoptions(flag, flagship);
	return (flagship);
>>>>>>> 2d3c73c6369652907978c5502bbd6962989f4289
}
